# Qt 기반 Aiot 애플리케이션 분석

## 1. 개요

이 애플리케이션은 라즈베리파이와 같은 임베디드 환경에서 LED 및 버튼(Key)을 제어하기 위해 만든 예제이다.

핵심 기능은 [디바이스 드라이버(ledkey_poll_dev.c)](https://github.com/KimMS-99/IntelAISW_LinuxBsp/tree/main/p432_ledkey_poll)와 연동하여 하드웨어를 제어하는 것으로, 이 드라이버를 커널에 올리면(`/dev/ledkey` 디바이스 파일 생성), 본 Qt 애플리케이션을 통해 LED를 켜고 끄며, 버튼 입력을 GUI에 실시간으로 반영할 수 있음.

## 2. 사전 준비 사항

이 Qt 애플리케이션을 실행하기 전에, 타겟 보드(라즈베리파이)에서 다음 작업이 반드시 선행되어야 함.

1.  **커널 모듈 적재**: 컴파일된 디바이스 드라이버 파일(`ledkey_poll_dev.ko`)을 커널에 로드.
    ```bash
    sudo insmod ledkey_poll_dev.Ko
    ```

2.  **디바이스 파일 생성**: 애플리케이션이 드라이버와 통신할 수 있도록 `/dev` 디렉토리에 캐릭터 디바이스 파일을 생성. 이때 주 번호(Major Number)는 드라이버 코드에 명시된 `230`을 사용해야 함.
    ```bash
    sudo mknod /dev/ledkey c 230 0
    ```

위 과정이 정상적으로 완료되어야만 본 애플리케이션이 `/dev/ledkey` 파일을 통해 하드웨어를 제어가능.

## 3. 핵심 클래스 및 역할

### `LedKeyDev` 클래스 (`ledkeydev.h`, `ledkeydev.cpp`)

`LedKeyDev` 클래스는 `/dev/ledkey` 디바이스 드라이버와 직접 통신하는 역할을 담당하는 핵심 브릿지.

-   **파일 열기**: 생성자에서 `QFile`을 사용하여 `/dev/ledkey` 디바이스 파일을 엽니다. 파일 열기에 실패하면 메시지 박스를 통해 사용자에게 알림.
-   **데이터 쓰기 (`writeLedDataSlot`)**: `pQFile->write()`를 호출하여 디바이스 드라이버에 데이터를 전송. 이 데이터는 8개의 LED 상태를 제어하는 데 사용됩니다. (예: 1바이트 값의 각 비트가 개별 LED에 해당)
-   **데이터 읽기 (`readKeyDataSlot`)**: `QSocketNotifier`를 사용하여 디바이스 파일의 상태를 비동기적으로 감시. 버튼이 눌려 드라이버로부터 읽을 데이터가 생기면 `activated` 시그널이 발생하고, `readKeyDataSlot`이 호출. 여기서 `pQFile->read()`를 통해 눌린 버튼 번호를 읽어오고, `updateKeyDataSig` 시그널을 통해 다른 클래스에 이 정보를 전달.

### `Tab1DevControl` 클래스 (`tab1devcontrol.h`, `tab1devcontrol.cpp`)

`Tab1DevControl` 클래스는 사용자 인터페이스(UI)의 실제 동작을 정의하고, `LedKeyDev`를 통해 하드웨어를 제어함.

-   **UI 요소 초기화**: 생성자에서 다이얼, 프로그레스 바, 체크박스(Key 상태 표시용), 타이머 등 UI 위젯들을 초기화하고 `LedKeyDev` 객체를 생성.
-   **시그널-슬롯 연결**: Qt의 시그널-슬롯 메커니즘을 사용하여 UI 이벤트와 처리 함수를 연결.
    -   `pDialLed` (다이얼)의 값이 바뀌면 -> `pLedKeyDev->writeLedDataSlot`을 호출하여 LED 상태를 변경.
    -   `pLedKeyDev`로부터 `updateKeyDataSig` (버튼 입력) 시그널이 오면 -> `updateCheckBoxKeySlot`을 호출하여 UI의 체크박스 상태와 LCD 숫자를 업데이트.
    -   UI의 체크박스를 직접 클릭하면 -> `updateCheckBoxMouseSlot`을 호출하여 LED 상태를 변경.
    -   타이머(`pQTimer`)가 만료되면 -> `updateDialValueSlot`을 호출하여 다이얼 값을 자동으로 증가.
-   **상태 관리**: `lcdData` 변수를 통해 현재 LED 및 Key 상태를 비트 연산으로 관리하고, 이를 LCD Number 위젯에 표시.

### 다. `MainWidget` 클래스 (`mainwidget.cpp`)

애플리케이션의 메인 윈도우 역할.

-   `Tab1DevControl`의 인스턴스를 생성하여 탭 위젯(`pTab1`)에 추가하고, 레이아웃을 설정하여 화면에 표시.

## 3. 전체 동작 흐름

1.  **애플리케이션 시작**: `MainWidget`이 생성되고, 그 안에 `Tab1DevControl` 위젯이 로드.
2.  **디바이스 드라이버 연동**: `Tab1DevControl`은 `LedKeyDev` 객체를 생성하고, `LedKeyDev`는 `/dev/ledkey` 디바이스 파일을 연다.
3.  **LED 제어 (출력)**:
    -   사용자가 UI의 다이얼(`pDialLed`)을 돌리거나 체크박스를 클릭.
    -   연결된 슬롯(`updateProgressBarLedSlot`, `updateCheckBoxMouseSlot`)이 호출.
    -   `pLedKeyDev->writeLedDataSlot`을 통해 해당 값이 디바이스 드라이버로 전달.
    -   드라이버는 전달받은 값으로 실제 LED의 ON/OFF 상태를 변경.
4.  **Key 입력 처리 (입력)**:
    -   사용자가 하드웨어 버튼을 누른다.
    -   디바이스 드라이버가 인터럽트를 통해 이를 감지하고, `/dev/ledkey` 파일에 키 정보를 기록.
    -   `QSocketNotifier`가 데이터가 있음을 감지하고 `activated` 시그널을 보냄.
    -   `LedKeyDev`의 `readKeyDataSlot`이 호출되어 키 값을 읽고, `updateKeyDataSig` 시그널을 발생.
    -   `Tab1DevControl`의 `updateCheckBoxKeySlot`이 이 시그널을 받아 UI(체크박스, LCD)를 업데이트하고, 동시에 해당 키 값으로 LED 상태도 변경.

이처럼 Aiot 애플리케이션은 **UI(Qt) ↔ `LedKeyDev` ↔ 디바이스 드라이버 ↔ 하드웨어(LED/Key)** 의 구조로 명확하게 역할이 분리되어 있으며, Qt의 시그널-슬롯 메커니즘을 통해 각 컴포넌트가 효율적으로 상호작용합니다.

+ **화면**
<img width="581" height="493" alt="실행 화면" src="https://github.com/user-attachments/assets/951b9522-0381-4c64-8dd0-c12e517fff37" />
