# QTextBrowser 위젯

**QTextBrowser** 위젯은 여러 줄의 문자열을 표시할 때 사용할 수 있다. 웹에서 문서를 표현할 때 사용하는 하이퍼텍스트(HyperText)를 표시할 때도 사용할 수 있다. 이 기능을 이용해서 간단한 **HTML** 문서를 표시할 수 있는데, 표나 프레임은 표시가 불가능하지만 리치 텍스트는 가능하다.

**HTML** 문서에 링크(Anchor)가 있을 때 backward(), forward(), home(), reload() 메소드로 인터넷 탐색에서의 문서 탐색과 같은 기능들을 수행할 수 있다. HTML 문서의 태그를 문자 형태로 보여주고 싶으면 **QTextEdit::setPlainText()** 메소드를 이용할 수 있으며, HTML 서식을 적용해서 표시하고 싶으면 **QTextEdit::setHTML()** 메소드를 사용하면 된다.

**QTextBrowser** 위젯에 문서를 지정할 때는 **QUrl** 클래스를 사용하는데, **QUrl** 클래스는 URL을 지정하기 위해 **Qt**에서 제공하는 클래스이다. ***TextBrowser.cpp***코드를 빌드하고 실행할 때는 ***index.html***파일이 필요하다

+ ***실행 결과***
<img width="249" height="224" alt="textbrowser" src="https://github.com/user-attachments/assets/dccfbd6c-76c1-4630-be72-3772d2057a5b" />
