#include "Master/Socket/xudpsocket.h"

/*-----------------------------------------------------------------+
| Constructor
+------------------------------------------------------------------+
| Parameters:
|   none
| Return:
|   none
+-----------------------------------------------------------------*/
XUdpSocket::XUdpSocket(QObject *parent):
    QObject(parent)
{
    mSocket = new QUdpSocket(this);
}

void XUdpSocket::initSocket(XHostAddress *address)
{
    mSocket->bind(address->getAddress(), address->getPort());

    connect(mSocket, SIGNAL(readyRead()),
            this, SLOT(readPendingDatagrams()));
}

bool XUdpSocket::writeData(QByteArray data, XHostAddress *address)
{

    bool wroteData = false;

    qint64 bytesSent = mSocket->writeDatagram(data, address->getAddress(), address->getPort());

    if(data.size() == bytesSent)
    {
        wroteData = true;
    }

    qDebug() << "Sending" << data << "to" << address->getAddress() << ":" << address->getPort();


    return wroteData;
}

void XUdpSocket::readPendingDatagrams()
{
    while (mSocket->hasPendingDatagrams()) {

        QByteArray datagram;
        datagram.resize(mSocket->pendingDatagramSize());

        QHostAddress sender;
        quint16 senderPort;

        mSocket->readDatagram(datagram.data(), datagram.size(),
                                &sender, &senderPort);

        if(!datagram.isEmpty())
        {
            emit gotDatagrams(datagram);
            datagram.clear();
        }
    }
}
