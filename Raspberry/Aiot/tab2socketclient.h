#ifndef TAB2SOCKETCLIENT_H
#define TAB2SOCKETCLIENT_H

#include <QWidget>
#include <QDebug>
#include <QTime>
#include <QDebug>
#include "sockclient.h"

namespace Ui {
class Tab2socketclient;
}

class Tab2socketclient : public QWidget
{
    Q_OBJECT
public:
    explicit Tab2socketclient(QWidget *parent = nullptr);
    ~Tab2socketclient();

private slots:
    void on_pPBserverConnect_toggled(bool checked);
    void updateRecvDataSlot(QString);

    void on_pPBrecvDataClear_clicked();

    void on_pPBSend_clicked();
    void socketSendToLinux(int);

signals:
    void ledWriteSig(int);

private:
    Ui::Tab2socketclient *ui;
    SockClient *pSockClient; // 소켓 클라이언트 포인터 변수
};

#endif // TAB2SOCKETCLIENT_H
