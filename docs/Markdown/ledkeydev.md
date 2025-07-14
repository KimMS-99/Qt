# `LedKeyDev` 클래스 (`ledkeydev.h`, `ledkeydev.cpp`)

`LedKeyDev` 클래스는 `/dev/ledkey` 디바이스 드라이버와 직접 통신하는 역할을 담당하는 핵심 브릿지로, 이 클래스는 LED 제어 및 버튼 입력 감지 기능을 제공한다.

## 주요 기능 및 역할

-   **파일 열기**: 생성자에서 `QFile`을 사용하여 `/dev/ledkey` 디바이스 파일을 엽니다. 파일 열기에 실패하면 메시지 박스를 통해 사용자에게 알림을 준다.
-   **데이터 쓰기 (`writeLedDataSlot`)**: `pQFile->write()`를 호출하여 디바이스 드라이버에 데이터를 전송합니다. 이 데이터는 8개의 LED 상태를 제어하는 데 사용된다. (예: 1바이트 값의 각 비트가 개별 LED에 해당)
-   **데이터 읽기 (`readKeyDataSlot`)**: `QSocketNotifier`를 사용하여 디바이스 파일의 상태를 비동기적으로 감시. 버튼이 눌려 드라이버로부터 읽을 데이터가 생기면 `activated` 시그널이 발생하고, `readKeyDataSlot`이 호출된다. 여기서 `pQFile->read()`를 통해 눌린 버튼 번호를 읽어오고, `updateKeyDataSig` 시그널을 통해 다른 클래스에 이 정보를 전달한다.

## 멤버 변수

-   `QFile *pQFile`: 디바이스 파일(`dev/ledkey`)과의 통신을 위한 파일 객체 포인터.
-   `QSocketNotifier *pQSocketNotifier`: 디바이스 파일의 읽기 이벤트를 감지하는 데 사용되는 소켓 알리미 객체 포인터.
-   `QString DEVFILENAME`: 디바이스 파일의 경로 (기본값: "/dev/ledkey").

## 슬롯 (Slots)

-   `readKeyDataSlot(int)`:
    -   디바이스 파일에서 읽을 데이터가 있을 때 `QSocketNotifier`에 의해 호출되는 슬롯.
    -   읽어온 버튼 데이터를 `updateKeyDataSig` 시그널을 통해 전달합니다.
-   `writeLedDataSlot(int ledValue)`:
    -   LED 상태를 제어하기 위해 디바이스 드라이버에 데이터를 쓰는 슬롯.
    -   `ledValue`는 8개의 LED 상태를 나타내는 정수 값.

## 시그널 (Signals)

-   `updateKeyDataSig(int)`:
    -   버튼 입력이 감지되어 새로운 키 데이터가 있을 때 발생하는 시그널.
    -   눌린 버튼의 번호를 인자로 전달.
