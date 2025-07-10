#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    pTab1DevControl = new Tab1DevControl(ui->pTab1);
    ui->pTab1->setLayout(pTab1DevControl->layout()); // 크기 자동 조정

    ui->pTabWidget->setCurrentIndex(0); // 첫 번째 탭을 디폴트로
}

MainWidget::~MainWidget()
{
    delete ui;
}
