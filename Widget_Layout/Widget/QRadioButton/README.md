# QRadioButton 위젯

라디오 버튼은 사용자로부터 복수의 옵션 중 하나만 선택할 때 사용한다.

라디오 버튼은 여러 버튼 중에 하나의 버튼이 이미 선택되어 있을 때 다른 버튼을 선택하면, 기존 버튼의 선택이 해제되고 새로 선택된 버튼먼 선택한다. 이와 같이 동작하도록 하기 위해서는 여러 라디오 버튼들을 **QButton** 클래스를 사용해서 하나의 그룹으로 묶어서 사용해야 한다.

현재 버튼이 선택되었는지 확인하기 위해 **isChecked()** 메소드를 사용하면 되고, 버튼을 설정할 수 있도록 **setChekced()**메소드를 제공한다.

***RadioButton.cpp***을 보면 먼저 라디오 버튼들을 배치하는데, **QWidget** 클래스의 **move()** 메소드를 사용할 수 있다. 버튼의 문자열을 보면 숫자 앞에 '&' 기호를 사용한다. 버튼의 문자열 앞에 '&' 기호를 사용하면 버튼에 단축키(Accelerator)를 지정할 수 있는데, 키보드의 'Alt + 단축키'로 버튼을 바로 선택할 수 있다.

라디오 버튼 객체를 만들고 그룹으로 묶기 위해서는 **QButtonGroup** 클래스를 사용하면 된다. 이 코드를 실행해보면 기존의 버튼이 선택되어 있을 때 다른 버튼을 선택하면 이전 버튼의 선택이 해제되면서 라디오 버튼처럼 동작하는 것을 확인할 수 있다.

+ ***실행 결과***<br>
![radiobutton](https://github.com/user-attachments/assets/bf94e5da-3318-4eb7-86ff-eba8013b5d91)
![radiobutton2](https://github.com/user-attachments/assets/ebece876-3806-41fc-9aa7-b4d734d7082f)
![radiobutton3](https://github.com/user-attachments/assets/ae6ef567-d2ed-49f2-9c96-9abe9984e4f6)
