# QScrollrBar 위젯

**QScrollBar** 위젯은 수직 또는 수평의 스크롤바를 제공하는데, 마우스로 스크롤바의 버튼을 클릭하거나 스크롤바 중앙의 핸들을 이용해서 값을 설정할 수 있다. 기본적으로 스크롤바는 슬라이더와 비슷한데 주로 값을 입력받기 위해 사용하는 것이 아니라 **QTextBrowser** 위젯이나 **QTableView** 위젯과 같이 스크롤 영역을 가진 위젯에서 현재 보여지는 부분이 전체의 어느 부분에 있는지 알고 싶은 경우에 사용될 수 있다.

**QTextEdit** 위젯과 같이 **QAbstractScrollArea** 클래스를 상속받는 클래스에서 수평 스크롤바는 **horizontalScrollBar()** 메소드를 통해서 가져올 수 있고, 수직 스크롤바는 verticalScrollBar() 메소드를 통해서 가져올 수 있다.