#include <QApplication>
#include <QPushButton>
#include <QLabel>

// Qt에서의 이벤트 처리
int main(int argc, char **argv)
{
	QApplication app(argc, argv);

	QPushButton *button = new QPushButton("Quit", 0);
	button->resize(120, 35); // 위젯의 크기 설정
	button->move(300, 300); // 위젯의 위치 설정
	QObject::connect(button, SIGNAL(clicked()), &app, SLOT(quit())); // 버튼이 클릭되면 'app'을 종료
	button->show(); // 위젯의 화면 표시

	QLabel *hello = new QLabel("<font color=blue>Hello <i>World!</i></font>", 0);
    hello->resize(300, 80); // 사이즈 지정
    hello->move(500, 180); // x : 500, y : 200
    hello->show(); // 위젯의 화면 표시

	return app.exec();
}
