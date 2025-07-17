#include "tab5sensordatabase.h"
#include "ui_tab5sensordatabase.h"

Tab5sensordatabase::Tab5sensordatabase(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Tab5sensordatabase)
{
    ui->setupUi(this);
    qSqlDatabase = QSqlDatabase::addDatabase("QSQLITE");
    qSqlDatabase.setDatabaseName("aiot.db");
    if(qSqlDatabase.open())
        qDebug() << "Success DB Connection";
    else
        qDebug() << "Fail DB Connection";
    QString strQuery = "create table sensor_tb ("
                        "name varchar(10), "
                        "date DATETIME primary key, "
                       "illu varchar(10),"
                       "temp varchar(10),"
                       "humi varchar(10))";
    QSqlQuery sqlQuery;
    if(sqlQuery.exec(strQuery))
        qDebug() << "Create Table";

    illuline = new QLineSeries(this);
    illuline->setName("조도");
    temp = new QLineSeries(this);
    temp->setName("온도");
    humi = new QLineSeries(this);
    humi->setName("습도");

    QPen pen;
    pen.setWidth(2);
    pen.setBrush(Qt::red);
    pen.setCapStyle(Qt::FlatCap);
    pen.setJoinStyle(Qt::MiterJoin);
    illuline->setPen(pen);

    pen.setWidth(2);
    pen.setBrush(Qt::green);
    pen.setCapStyle(Qt::FlatCap);
    pen.setJoinStyle(Qt::MiterJoin);
    temp->setPen(pen);

    pen.setWidth(2);
    pen.setBrush(Qt::blue);
    pen.setCapStyle(Qt::FlatCap);
    pen.setJoinStyle(Qt::MiterJoin);
    humi->setPen(pen);

    pQChart = new QChart();
    pQChart->addSeries(illuline);
    pQChart->addSeries(temp);
    pQChart->addSeries(humi);
    pQChart->createDefaultAxes(); // 좌표 디폴트
    pQChart->axes(Qt::Vertical).constFirst()->setRange(0, 100);

    pQChartView = new QChartView(pQChart);
    pQChartView->setRenderHint(QPainter::Antialiasing);

    ui->pChartViewLayout->layout()->addWidget(pQChartView);
    pQDateTimeAxisX = new QDateTimeAxis;
    pQDateTimeAxisX->setFormat("hh:mm");
    // pQDateTimeAxisX->setFormat("MM-dd hh:mm:ss"); // 날짜 시분초

    updateLastDateTimeSql(0);
    pQChartView->chart()->setAxisX(pQDateTimeAxisX, illuline);
    pQChartView->chart()->setAxisX(pQDateTimeAxisX, temp);
    pQChartView->chart()->setAxisX(pQDateTimeAxisX, humi);
}

void Tab5sensordatabase::updateLastDateTimeSql(bool bFlag)
{
    QDateTime fromDateTime = ui->pDateTimeEditFrom->dateTime();
    QString strFromDateTime = fromDateTime.toString("yyyy/MM/dd hh:mm:ss");
    QDateTime toDateTime = ui->pDateTimeEditTo->dateTime();
    QString strToDateTime = toDateTime.toString("yyyy/MM/dd hh:mm:ss");

    pQDateTimeAxisX->setRange(fromDateTime, toDateTime);
}

void Tab5sensordatabase::Tab5RecvDataSlot(QString recvData)
{
    // QDate date = QDate::currentDate();
    // QTime time = QTime::currentTime();
    // QDateTime xValue;
    // xValue.setDate(date);
    // xValue.setTime(time);
    QDateTime dateTime = QDateTime::currentDateTime();

    // qDebug() << "recvData : " << recvData;

    QStringList strList = recvData.split("@"); // recvData : [SENSORID]SENSOR@조도@온도@습도
    QString name = strList[1]; // name 예) KMS_LIN
    QString illu = strList[3]; // 조도
    QString tmp = strList[4]; // 온도
    QString hum = strList[5]; // 습도
    qDebug() << "illu : " << illu.toInt() << "tmp : " << tmp.toFloat() << "hum : " << hum.toFloat();

    QString strQuery = "insert into sensor_tb(name, date, illu, temp, humi)"
                       "values('"+ name + "', '" + dateTime.toString("yyyy/MM/dd hh:mm:ss") + "', '" + illu + "', '" + tmp + "', '" + hum + "')";
    QSqlQuery sqlQuery;
    if(sqlQuery.exec(strQuery))
        qDebug() << "Insert Query Ok";
}

Tab5sensordatabase::~Tab5sensordatabase()
{
    delete ui;
}

void Tab5sensordatabase::on_pushButton_clicked()
{
    updateLastDateTimeSql(0);
    illuline->clear();
    temp->clear();
    humi->clear();
    ui->pTBsensor->setRowCount(0); // 모든 행 삭제
}

void Tab5sensordatabase::on_pPBsearchDB_clicked()
{
    QDateTime fromDateTime = ui->pDateTimeEditFrom->dateTime();
    QDateTime toDateTime = ui->pDateTimeEditTo->dateTime();

    ui->pTBsensor->clearContents(); // 셀에 있는 QTableWidgetItem을 전부 delete함, 행/열은 그대로 유지된다.
    on_pushButton_clicked();

    QString strQuery = "select * from sensor_tb where '" + fromDateTime.toString("yyyy/MM/dd hh:mm:ss") + "' <= date and date <= '" + toDateTime.toString("yyyy/MM/dd hh:mm:ss") + "'";
    QSqlQuery sqlQuery;
    if(sqlQuery.exec(strQuery))
    {
        qDebug() << "Select Query Ok";
        int rowCount = 0;

        QDateTime firstDateTime;
        QDateTime lastDateTime;

#if PROFESSOR_CODE
        if(sqlQuery.exec(strQuery))
        {
            int rowCount=0;
            qDebug() << "Select Query Ok";
            while(sqlQuery.next())
                rowCount++;

            // if(pQTableWidgetItemId != nullptr)
            // {
            //     delete [] pQTableWidgetItemId;
            //     delete [] pQTableWidgetItemDate;
            //     delete [] pQTableWidgetItemIllu;
            // }

            pQTableWidgetItemId = new QTableWidgetItem[rowCount];
            pQTableWidgetItemDate = new QTableWidgetItem[rowCount];
            pQTableWidgetItemIllu = new QTableWidgetItem[rowCount];

            rowCount=0;
            sqlQuery.first();
            while(sqlQuery.next())
            {
                ui->pTBsensor->setRowCount(rowCount+1);

                (pQTableWidgetItemId+rowCount)->setText(sqlQuery.value("name").toString());
                (pQTableWidgetItemDate+rowCount)->setText(sqlQuery.value("date").toString());
                (pQTableWidgetItemIllu+rowCount)->setText(sqlQuery.value("illu").toString());

                ui->pTBsensor->setItem(rowCount,0, (pQTableWidgetItemId+rowCount));
                ui->pTBsensor->setItem(rowCount,1, (pQTableWidgetItemDate+rowCount));
                ui->pTBsensor->setItem(rowCount,2, (pQTableWidgetItemIllu+rowCount));

                QDateTime xValue = QDateTime::fromString((pQTableWidgetItemDate+rowCount)->text(), "yyyy/MM/dd hh:mm:ss");
                illuline->append(xValue.toMSecsSinceEpoch(),(pQTableWidgetItemIllu+rowCount)->text().toInt());
                rowCount++;
            }
            ui->pTBsensor->resizeColumnToContents(0);
            ui->pTBsensor->resizeColumnToContents(1);
            ui->pTBsensor->resizeColumnToContents(2);
        }
#else
        while(sqlQuery.next())
        {
            /* 그래프 커서 위치 설정 방법 1번 */
            // if(rowCount == 0)
            // {
            //     firstDateTime = QDateTime::fromString(sqlQuery.value("date").toString(), "yyyy/MM/dd hh:mm:ss");
            // }
            // lastDateTime = QDateTime::fromString(sqlQuery.value("date").toString(), "yyyy/MM/dd hh:mm:ss");

            rowCount++;
            ui->pTBsensor->setRowCount(rowCount);

            QTableWidgetItem * pQTableWidgetItemId = new QTableWidgetItem();
            QTableWidgetItem * pQTableWidgetItemDate = new QTableWidgetItem();
            QTableWidgetItem * pQTableWidgetItemIllu = new QTableWidgetItem();
            QTableWidgetItem * pQTableWidgetItemTemp = new QTableWidgetItem();
            QTableWidgetItem * pQTableWidgetItemHumi = new QTableWidgetItem();

            pQTableWidgetItemId->setText(sqlQuery.value("name").toString());
            pQTableWidgetItemDate->setText(sqlQuery.value("date").toString());
            pQTableWidgetItemIllu->setText(sqlQuery.value("illu").toString());
            pQTableWidgetItemTemp->setText(sqlQuery.value("temp").toString());
            pQTableWidgetItemHumi->setText(sqlQuery.value("humi").toString());

            /* setItem()은 QTableWidget에게 소유권을 줘서 Qt가 관리하게 하고 동적메모리 해제 시점은 보통 clearContents() 호출, setItem()으로 기존 아이템을 덮을 때,  QTableWidget 자체가 소멸될 때 */
            ui->pTBsensor->setItem(rowCount-1, 0, pQTableWidgetItemId);
            ui->pTBsensor->setItem(rowCount-1, 1, pQTableWidgetItemDate);
            ui->pTBsensor->setItem(rowCount-1, 2, pQTableWidgetItemIllu);
            ui->pTBsensor->setItem(rowCount-1, 3, pQTableWidgetItemTemp);
            ui->pTBsensor->setItem(rowCount-1, 4, pQTableWidgetItemHumi);

            QDateTime sqlDateTime = QDateTime::fromString(sqlQuery.value("date").toString(), "yyyy/MM/dd hh:mm:ss");

            illuline->append(sqlDateTime.toMSecsSinceEpoch(), sqlQuery.value("illu").toInt());
            temp->append(sqlDateTime.toMSecsSinceEpoch(), sqlQuery.value("temp").toFloat());
            humi->append(sqlDateTime.toMSecsSinceEpoch(), sqlQuery.value("humi").toFloat());
        }

        /* 그래프 커서 위치 설정 방법 1번 */
        // // 데이터가 하나라도 있으면
        // if(firstDateTime.isValid() && lastDateTime.isValid())
        // {
        //     pQDateTimeAxisX->setRange(firstDateTime, lastDateTime);
        // } else
        // {
        //     // 데이터 없으면 기존 UI 범위로 설정
        //     pQDateTimeAxisX->setRange(fromDateTime, toDateTime);
        // }

        /* 그래프 커서 위치 설정 방법 2번 */
        sqlQuery.first();
        firstDateTime = QDateTime::fromString(sqlQuery.value("date").toString(), "yyyy/MM/dd hh:mm:ss");
        sqlQuery.last();
        lastDateTime = QDateTime::fromString(sqlQuery.value("date").toString(), "yyyy/MM/dd hh:mm:ss");
        if(firstDateTime.isValid() && lastDateTime.isValid())
        {

            pQDateTimeAxisX->setRange(firstDateTime, lastDateTime);
        } else
        {
            // 데이터 없으면 기존 UI 범위로 설정
            pQDateTimeAxisX->setRange(fromDateTime, toDateTime);
        }

        // ui->pTBsensor->resizeColumnToContents(0);
        // ui->pTBsensor->resizeColumnToContents(1);
        // ui->pTBsensor->resizeColumnToContents(2);
        // ui->pTBsensor->resizeColumnToContents(3);
        // ui->pTBsensor->resizeColumnToContents(4);
        ui->pTBsensor->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
#endif
    }
}


void Tab5sensordatabase::on_pPBdeleteDB_clicked() // 날짜에 해당하는 db삭제
{
    QDateTime fromDateTime = ui->pDateTimeEditFrom->dateTime();
    QString strFromDateTime = fromDateTime.toString("yyyy/MM/dd hh:mm:ss");
    QDateTime toDateTime = ui->pDateTimeEditTo->dateTime();
    QString strToDateTime = toDateTime.toString("yyyy/MM/dd hh:mm:ss");
    QString strQuery = "delete from sensor_tb where '" + strFromDateTime + "' <= date and date <= '" + strToDateTime + "'";
    QSqlQuery sqlQuery;
    if(sqlQuery.exec(strQuery))
    {
        qDebug() << "Delete Query Ok";
        illuline->clear();
        temp->clear();
        humi->clear();
        ui->pTBsensor->clearContents();
        ui->pTBsensor->setRowCount(0);
    }
}

