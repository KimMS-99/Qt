#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include "customwidget.h"

CustomWidget::CustomWidget(QWidget *parent) : QWidget(parent)
{
	QPushButton *button = new QPushButton("Quit", this);
	button->resize(120, 35); // 위젯의 크기 설정
	button->move(50, 50);

	QLabel *hello = new QLabel("<font color=blue>Hello <i>World!</i></font>", this);
	hello->move(50, 100);

	this->resize(220, 135); // 윈도우의 크기 설정
	move(300, 300); // 윈도우의 위치 설정, this 생략

//	connect(button, SIGNAL(clicked()), qApp, SLOT(quit())); 
	connect(button, SIGNAL(clicked()), this, SLOT(processClick())); // 시그널/슬롯 연결
//	connect(this, SIGNAL(widgetClicked()), qApp, SLOT(quit()));
}

void CustomWidget::processClick()
{
	qDebug() << "processClick()";
	emit widgetClicked(); // 사용자 정의 시그널 발생
}
