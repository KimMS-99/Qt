# Intel_Edge_AI_SW-Qt
[Qt 공식문서](https://doc.qt.io/qt-6.8/index.html)
+ Qt 6.8 버전의 기능/클래스 설명
+ 개발자 가이드 / 튜토리얼
+ 모듈별 설명
---
## 목차
1. [Qt 프로젝트 파일(.pro)이란?](#qt-프로젝트-파일pro이란)<br>
2. Qt 프로그래밍과 사용자 정의 위젯
- [Qt에서의 이벤트 처리](button)
- [사용자 정의 위젯, 사용자 정의 시그널과 슬롯](customwidget)<br>
3. Qt 
---

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
