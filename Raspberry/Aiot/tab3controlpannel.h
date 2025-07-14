#ifndef TAB3CONTROLPANNEL_H
#define TAB3CONTROLPANNEL_H

#include <QWidget>

namespace Ui {
class Tab3ControlPannel;
}

class Tab3ControlPannel : public QWidget
{
    Q_OBJECT

public:
    explicit Tab3ControlPannel(QWidget *parent = nullptr);
    ~Tab3ControlPannel();

private:
    Ui::Tab3ControlPannel *ui;
};

#endif // TAB3CONTROLPANNEL_H
