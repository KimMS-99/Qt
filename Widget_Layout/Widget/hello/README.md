# Hello World! 프로그래밍!

**main()** 함수를 살펴보자. **Qt**는 항상 하나의 **QApplication** 클래스의 객체를 가지고 있어야 하며, 다른 **Qt**의 객체들보다 먼저 선언되어야 한다. 이러한 이유로 대부분의 **Qt**애플리케이션에서 **QApplication** 클래스는 주로 **main()**함수에서 사용한다.

**QApplication** 클래스는 **Qt**를 사용할 수 있도록 초기화하고, 사용자의 명령해 인수(command line argument)를 처리한다. 그리고 마지막 라인의 **QApplication** 클래스의 **exec()** 함수로 이벤트를 처리한다. 마지막 라인이 없으면 **main()** 함수가 종료되면서 애플리케이션도 종료된다.

**QApplication** 클래스의 객체를 생성한 후에는 **GUI** 객체를 만들어야 하는데 여기서는 **QLabel** 클래스의 객체를 사용한다. **QLabel** 위젯은 말 그대로 화면에 래이블(Label)을 만든다. **QLabel** 객체 생성 시 첫 번째 인자에는 화면에 표시될 문자열을 사용할 수 있다. 또한 **helloworld.cpp** 코드처럼 **HTML**을 사용해서 문자열에 생이나 크기 등의 서식이 있는 리치 텍스트(rich text)를 사용할 수 있다.

두 번째 인자에는 **QLabel**이 들어가야 할 부모 위젯을 설정할 수 있다. 일반적으로 위젯은 부모와 자식 관계를 가지고 있으며, 자식 위젯은 부모 위젯의 공간 내에서 표시된다. 일반적으로 위젯은 부모의 자식 관계를 가지고 있으며, 자식 위젯은 부모 위젯의 공간 내에서 표시된다. 만약 현재의 위젯을 별도의 창(top-level widget)으로 열어야 하는 경우에는 부모 위젯을 지정할 수 없는데 이때는 숫자 0(C++11에서는 nullptr)을 사용한다.

**QLabel** 객체를 바로 생성하면 메인 메모리상에만 존재하고 사용자에게 보이지 않는다. 이를 사용자에게 보여주기 위해서는 **QWidget** 클래스의 **show()**메소드를 사용한다. 일반적으로 임베디드 장비의 경우 화면 갱신이 늦기 때문에 위젯을을 화면에 나타낸 후 속성을 변경하면 변경 과정이 사용자에게 보이게 된다.

**Qt** 프로그램을 제대로 실행하기 위해서는 환경 변수인 **QTDIR**, **PATH**, **LED_LIBRARY_PATH** 중에서 공유 라이브러리와 관련된 환경 변수인 **LED_LIBRARY_PATH**가 제대로 설정되어 있어야 한다.

+ ***실행 결과*** <br>
![hello1](https://github.com/user-attachments/assets/dfcf2a9e-f158-4efa-a70c-f346fe76b8bd)
![hello2](https://github.com/user-attachments/assets/6e50421d-66d6-41e2-b09a-d94b368bfffd)

# Qt의 위젯

**Qt**는 C++의 상속(ingeritance)을 지원한다. **Qt**에서의 모든 위젯은 **QWidget** 클래스를 상속받는다.
**QWidget**클래스는 화면의 표시되는 기본적인 성질에 대한 속성들을 담고 있다. **QWidget**에 대해 더 살펴보려면 **Qt**사이트의 Documentation 페이지를 참고.
[QWidget 도움말 페이지](https://doc.qt.io/qt-6.8/index.html)

**helloworld.cpp**에서 **QLabel** 클래스는 **QFrame** 클래스를 상속받고, **QFrame** 클래스는 **QWidget** 클래스를 상속받기 때문에 **QWidget**의 메소드를 사용할 수 있다.
