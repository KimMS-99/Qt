#include "ledkeydev.h"

LedKeyDev::LedKeyDev(QWidget *parent)
    : QWidget{parent}
{
    pQfile = new QFile(DEVFILENAME);
    if(!pQfile->open(QFile::ReadWrite | QFile::Unbuffered))
    {
        QMessageBox::information(this, "open", "open fail : " + DEVFILENAME);
    }
    ledKeyFd = pQfile->handle();
    pQSocketNotifier = new QSocketNotifier(ledKeyFd, QSocketNotifier::Read, this);
    connect(pQSocketNotifier, SIGNAL(activated(int)), this, SLOT(readKeyDataSlot(int)));

}
void LedKeyDev::readKeyDataSlot(int)
{
    char keyNo = 0;
    int ret = pQfile->read(&keyNo, sizeof(keyNo));
    if(ret > 0)
        emit updateKeyDataSig(int(keyNo));
    qDebug() << int(keyNo);
}

void LedKeyDev::writeLedDataSlot(int dialValue)
{
    char ledNo = (char)dialValue;
    pQfile->write(&ledNo, sizeof(ledNo));
    qDebug() << (unsigned char)(ledNo);
}
