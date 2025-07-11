# 위젯

## 목차

0. [Qt 프로그래밍과 사용자 정의 위젯](#qt-프로그래밍과-사용자-정의-위젯)
1. [HelloWorld](./hello/)
2. [QtEvent(Button)](./QtEvent(Button)/)
3. [CustomWidget](./CustomWidget/)
4. [QPushButton](./QPushButton/)
5. [QRadioButton](./QRadioButton/)
6. [QCheckBox](./QCheckBox/)
7. [QLabel](./QLabel/)
8. [QLCDNumber](./QLCDNumber/)
9. [QTextBrowser](./QTextBrowser/)
10. [QLineEdit](./QLineEdit/)
11. [QTextEdit](./QTextEdit/)
12. [QComboBox](./QComboBox/)
13. [QSpinBox](./QSpinBox/)
14. [QDial](./QDial/)
15. [QSlider](./QSlider/)
16. [QScrollBar](./QScrollBar/)

---

## Qt 프로그래밍과 사용자 정의 위젯

**Qt**는 강력한 위젯(Widget) 기반의 GUI 프레임워크로, 그래픽 사용자 인터페이스(GUI) 프로그래밍을 쉽게 할 수 있도록 다양한 **표준 위젯**을 제공한다.  
위젯은 MS Windows의 컨트롤(Control)과 유사한 개념으로, **사용자와 상호작용을 위한 인터페이스 요소**다.

**Qt**는 버튼(`QPushButton`), 레이블(`QLabel`), 체크박스(`QCheckBox`), 텍스트 박스(`QLineEdit`), 슬라이더(`QSlider`) 등 다양한 위젯 클래스를 제공하며,  
**GTK+나 다른 GUI 툴킷에 비해 현대적이고 일관된 외관**을 보여주는 것이 특징입니다.

또한, **Qt**에서는 이러한 표준 위젯 외에도 **사용자가 직접 위젯 클래스를 상속받아 새로운 동작이나 외형을 갖는 "사용자 정의 위젯(Custom Widget)"을 만들 수 있습니다.**

### 사용자 정의 위젯(Custom Widget)

**Qt**에서는 표준 위젯 외에도, 개발자가 직접 위젯 클래스를 새로운 기능과 외형을 가지는 **"사용자 정의 위젯"**을 만들 수 있다.
예를 들어, **Raspberry Pi**의 LED를 제어하는 버튼이나 센서 상태를 표시하는 전용 위젯 등을 구현할 수 있다.

사용자 정의 위젯은 일반적으로 다음 구조로 구성됨 :

+ 헤더 파일(.h): QWidget 클래스를 상속받은 클래스 정의

+ 소스 파일(.cpp): 생성자 구현 및 위젯 구성 (button, layout 등)

+ this 포인터를 활용해 하위 위젯을 현재 클래스 내부에 배치

+ qApp을 사용해서 전역 QApplication 객체에 액세스

