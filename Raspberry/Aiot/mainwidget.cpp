#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);

    // tab1
    pTab1DevControl = new Tab1DevControl(ui->pTab1);
    ui->pTab1->setLayout(pTab1DevControl->layout());

    // tab2
    pTab2socketclient = new Tab2socketclient(ui->pTab2);
    ui->pTab2->setLayout(pTab2socketclient->layout());

    // tab3
    pTab3ControlPannel = new Tab3ControlPannel(ui->pTab3);
    ui->pTab3->setLayout(pTab3ControlPannel->layout());

    ui->pTabWidget->setCurrentIndex(2); // 어떤 tab이 디폴트로 실행되게 할지

    connect(pTab2socketclient, SIGNAL(ledWriteSig(int)), pTab1DevControl->getpDial(), SLOT(setValue(int)));
    connect(pTab1DevControl->getpLedKeyDev(), SIGNAL(updateKeyDataSig(int)), pTab2socketclient, SLOT(socketSendToLinux(int)));

}

MainWidget::~MainWidget()
{
    delete ui;
}
