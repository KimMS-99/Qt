#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QWebEngineView>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWidget;
}
QT_END_NAMESPACE

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

private:
    Ui::MainWidget *ui;
    QWebEngineView *pQWebEngineView1;
    QWebEngineView *pQWebEngineView2;
    QWebEngineView *pQWebEngineView3;
    QWebEngineView *pQWebEngineView4;
};
#endif // MAINWIDGET_H
