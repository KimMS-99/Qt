#include <QApplication>
#include "customwidget.h"

// 사용자 정의 위젯 시그널 슬롯
int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	CustomWidget *widget = new CustomWidget(0);
	widget->show();
	QObject::connect(widget, SIGNAL(widgetClicked()), &app, SLOT(quit()));

	return app.exec();
}
