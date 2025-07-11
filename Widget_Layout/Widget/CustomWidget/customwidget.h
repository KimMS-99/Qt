#ifndef __CUSTOM_WIDGET__
#define __CUSTOM_WIDGET__

#include <QWidget>
#include <QDebug>

class CustomWidget : public QWidget
{
	Q_OBJECT
public:
	CustomWidget(QWidget *parent = 0);

signals:
	void widgetClicked(); // 사용자 정의 시그널

public slots:
	void processClick(); // 사용자 정의 슬롯
};

#endif
