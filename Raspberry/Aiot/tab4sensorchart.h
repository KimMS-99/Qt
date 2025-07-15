#ifndef TAB4SENSORCHART_H
#define TAB4SENSORCHART_H

#include <QWidget>
#include <QChartView>
#include <QLineSeries>
#include <QDateTimeAxis> // 가로축으로 날짜 시간을 사용
#include <QDate>
#include <QTime>
#include <QDebug>

namespace Ui {
class Tab4SensorChart;
}

class Tab4SensorChart : public QWidget
{
    Q_OBJECT

public:
    explicit Tab4SensorChart(QWidget *parent = nullptr);
    ~Tab4SensorChart();

private:
    Ui::Tab4SensorChart *ui;
    QLineSeries * illuline; // 조도
    QLineSeries * humi; // 습도
    QLineSeries * temp; // 온도
    QChart * pQChart;
    QChartView * pQChartView;
    QDateTimeAxis *pQDateTimeAxisX;
    QDateTime firstDateTime;
    QDateTime lastDateTime;

    void updateLastDateTime(bool);

private slots:
    void Tab4RecvDataSlot(QString);
    void on_pPBClearChart_clicked();
};

#endif // TAB4SENSORCHART_H
