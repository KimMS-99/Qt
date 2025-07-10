/********************************************************************************
** Form generated from reading UI file 'mywidget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYWIDGET_H
#define UI_MYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDial>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyWidget
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QDial *dial;
    QProgressBar *progressBar;

    void setupUi(QWidget *MyWidget)
    {
        if (MyWidget->objectName().isEmpty())
            MyWidget->setObjectName("MyWidget");
        MyWidget->resize(400, 450);
        verticalLayoutWidget = new QWidget(MyWidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(10, 0, 371, 431));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        dial = new QDial(verticalLayoutWidget);
        dial->setObjectName("dial");
        dial->setEnabled(true);
        dial->setAutoFillBackground(false);
        dial->setMaximum(100);
        dial->setInvertedAppearance(false);
        dial->setInvertedControls(false);
        dial->setNotchesVisible(true);

        verticalLayout->addWidget(dial);

        progressBar = new QProgressBar(verticalLayoutWidget);
        progressBar->setObjectName("progressBar");
        progressBar->setValue(0);
        progressBar->setAlignment(Qt::AlignmentFlag::AlignCenter);
        progressBar->setTextVisible(true);

        verticalLayout->addWidget(progressBar);


        retranslateUi(MyWidget);
        QObject::connect(dial, &QDial::valueChanged, progressBar, &QProgressBar::setValue);

        QMetaObject::connectSlotsByName(MyWidget);
    } // setupUi

    void retranslateUi(QWidget *MyWidget)
    {
        MyWidget->setWindowTitle(QCoreApplication::translate("MyWidget", "MyWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyWidget: public Ui_MyWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYWIDGET_H
