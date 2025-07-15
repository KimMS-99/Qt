# Qt
[Qt 공식문서](https://doc.qt.io/qt-6.8/index.html)
+ Qt 6.8 버전의 기능/클래스 설명
+ 개발자 가이드 / 튜토리얼
+ 모듈별 설명

## Qt란?

Qt는 크로스플랫폼(Cross-Platform) 애플리케이션 개발을 위한 C++ 기반의 프레임워크 및 위젯 툴킷으로 GUI(그래픽 사용자 인터페이스) 프로그램을 만드는 데 주로 사용되지만, 네트워크, 데이터베이스, 멀티미디어 등 다양한 기능을 포함한 라이브러리를 제공하여 콘솔이나 서버용 프로그램 개발도 가능함.

### 1. 크로스플랫폼 지원 (Cross-Platform)
- **"한 번 작성하면, 어디서든 컴파일된다 (Write once, compile anywhere)"**는 철학을 따름.
- 동일한 소스 코드로 **Windows, macOS, Linux** 데스크톱 환경은 물론 **Android, iOS** 같은 모바일 환경, 그리고 **임베디드 시스템**에서도 네이티브 애플리케이션을 빌드할 수 있다.

### 2. C++ 기반
- Qt는 **C++**를 주력 언어로 사용하고, C++의 강력한 성능과 객체 지향 프로그래밍의 장점을 활용할 수 있다.
- Qt는 표준 C++에 **시그널과 슬롯(Signals & Slots)**, **메타 객체 시스템(Meta-Object System)** 등 고유한 기능을 추가하여 개발 편의성을 높였다.

### 3. 시그널과 슬롯 (Signals and Slots)
- Qt의 가장 독특하고 강력한 기능 중 하나이다.
- 객체 간의 통신을 위한 이벤트 처리 메커니즘으로, 특정 이벤트가 발생했을 때(시그널) 연결된 함수(슬롯)를 실행하도록 만든다.
- 이를 통해 객체 간의 의존성을 낮추고 유연한 프로그래밍이 가능하다.

### 4. 풍부한 클래스 라이브러리
- **GUI 위젯**: 버튼, 레이블, 텍스트 박스 등 다양한 UI 컴포넌트를 제공한다.
- **네트워킹**: HTTP, TCP, UDP 통신을 위한 클래스를 제공한다.
- **데이터베이스**: SQL 데이터베이스 연동을 지원한다.
- **멀티미디어**: 오디오, 비디오 처리를 위한 기능을 포함한다.
- **XML, JSON 파싱** 등 개발에 필요한 거의 모든 기능을 모듈화된 라이브러리로 제공한다.

### 5. Qt Creator IDE
- Qt는 **Qt Creator**라는 공식 통합 개발 환경(IDE)을 제공한다.
- 코드 편집기, GUI 레이아웃을 시각적으로 디자인할 수 있는 **Qt Designer**, 디버거 등이 포함되어 있어 개발 생산성을 크게 향상시킨다.

### 왜 Qt를 사용하는가?

- **높은 생산성**: 풍부한 라이브러리와 강력한 IDE 덕분에 빠르게 애플리케이션을 개발할 수 있다.
- **코드 재사용성**: 하나의 코드로 여러 플랫폼에서 동작하는 프로그램을 만들 수 있어 개발 비용과 시간을 절약할 수 있다.
- **고성능**: C++ 기반으로 작성되어 네이티브 코드에 가까운 성능을 보여준다.
- **활발한 커뮤니티와 문서**: 오랜 역사를 가진 만큼 방대한 문서와 튜토리얼, 활발한 개발자 커뮤니티를 보유하고 있다.

## Qt 클래스 상속 관계 정리

> Qt는 대부분의 클래스가 `QObject`을 기반으로 하며, 위젯 계열은 `QWidget` 계열로 구성됩니다.

---

### ✅ 기본 클래스 계층 구조

```plaintext
QObject
 ├── QCoreApplication
 │    └── QApplication
 ├── QTimer
 ├── QThread
 ├── QWidget
 │    ├── QMainWindow
 │    ├── QDialog
 │    ├── QFrame
 │    │    ├── QLabel
 │    │    ├── QLineEdit
 │    │    ├── QGroupBox
 │    ├── QPushButton
 │    ├── QCheckBox
 │    ├── QRadioButton
 │    ├── QComboBox
 │    ├── QTableWidget
 │    ├── QOpenGLWidget
 │    └── ...
 └── QAbstractItemModel
      ├── QStringListModel
      ├── QStandardItemModel
      └── ...
```

---

### ✅ 주요 클래스 설명

### 🔹 `QObject`
- 모든 Qt 클래스의 최상위 부모
- 시그널/슬롯 시스템 지원
- 메모리 관리(parent/child 관계)

### 🔹 `QWidget`
- 모든 GUI 위젯의 기반 클래스
- 창, 버튼, 텍스트박스 등 시각적 컴포넌트 제공

### 🔹 `QApplication`
- 이벤트 루프와 GUI 환경 초기화 담당
- `main()` 함수에서 사용

### 🔹 `QMainWindow`
- 메뉴, 툴바, 상태바를 포함한 표준 창 제공

### 🔹 위젯들 (`QPushButton`, `QLabel`, `QLineEdit` 등)
- `QWidget`을 상속하여 사용자와의 인터페이스 역할

---

### ✅ 시각적 요약 (UML 스타일)

```plaintext
QObject
├── QCoreApplication
│   └── QApplication
│       └── QWidget
│           ├── QMainWindow
│           ├── QDialog
│           ├── QPushButton
│           ├── QLineEdit
│           ├── QLabel
│           ├── QCheckBox
│           ├── QRadioButton
│           └── ...
├── QTimer
├── QThread
└── QAbstractItemModel
```

---

### ✅ 상속 경로 예시

| 기능            | 상속 구조                                    |
|-----------------|-----------------------------------------------|
| 메인 GUI 창     | `QObject` → `QWidget` → `QMainWindow`         |
| 버튼            | `QObject` → `QWidget` → `QPushButton`         |
| 입력창          | `QObject` → `QWidget` → `QLineEdit`           |
| 쓰레드 처리     | `QObject` → `QThread`                         |
| 타이머          | `QObject` → `QTimer`                          |
| 모델 클래스     | `QObject` → `QAbstractItemModel` → 하위 모델 |


## Qt 프로젝트 파일(.pro)이란?

`.pro` 파일은 Qt 프로젝트의 설정 파일입니다. `qmake` 빌드 시스템이 이 파일을 사용하여 프로젝트를 어떻게 빌드할지 결정합니다.

파일 안에는 다음과 같은 정보가 포함됩니다:
- **SOURCES**: 컴파일할 소스 코드 파일 목록
- **HEADERS**: 헤더 파일 목록
- **QT**: 프로젝트에서 사용할 Qt 모듈 (예: `core`, `gui`, `widgets`)
- **TARGET**: 생성될 실행 파일의 이름
- 기타 빌드 관련 설정 (예: 라이브러리 추가, 컴파일러 옵션)

`qmake`는 `.pro` 파일을 읽어 플랫폼에 맞는 `Makefile`을 생성하고, 이 `Makefile`을 통해 프로젝트가 컴파일됩니다.

### Qt 프로젝트(.pro) 생성 및 실행파일 만드는 방법(직접 만들 경우)

#### ✅ 기본으로 만들기

```bash
- qmake -project
- vi raspi.pro
```
.pro 파일이 자동 생성됨.
raspi.pro 파일 5번째 줄쯤에 아래 항목을 추가 또는 수정:
```bash
QT += widgets
``
```bash
qmake      # Makefile 생성
make       # 컴파일
./raspi    # 실행파일 실행 (기본 TARGET 이름 기준)
```

#### ✅ .pro 파일과 실행파일 이름 바꾸기
```bash
qmake -project -o helloqt.pro
vi helloqt.pro
```
- helloqt.pro 파일에 아래 내용을 추가 또는 수정:
```bash
QT += widgets
TARGET = helloqt
```
```bash
qmake      # Makefile 생성
make       # 컴파일
./helloqt  # 실행
```
---