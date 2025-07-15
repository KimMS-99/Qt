#ifndef TAB4LINECHART_H
#define TAB4LINECHART_H

#include <QWidget>

namespace Ui {
class Tab4LineChart;
}

class Tab4LineChart : public QWidget
{
    Q_OBJECT

public:
    explicit Tab4LineChart(QWidget *parent = nullptr);
    ~Tab4LineChart();

private:
    Ui::Tab4LineChart *ui;
};

#endif // TAB4LINECHART_H
