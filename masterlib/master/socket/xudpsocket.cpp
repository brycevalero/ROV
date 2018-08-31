#include "Master/Socket/xudpsocket.h"

/*-----------------------------------------------------------------+
| Constructor
+------------------------------------------------------------------+
| Parameters:
|   parent (QObject): parent object
+-----------------------------------------------------------------*/
XUdpSocket::XUdpSocket(QObject *parent):
    QObject(parent)
{
    mSocket = new QUdpSocket(this);
}

/*-----------------------------------------------------------------+
| Bind to a socket at specific address/port
+------------------------------------------------------------------+
| Parameters:
|   address (XHostAddress): address/port paring
+-----------------------------------------------------------------*/
void XUdpSocket::initSocket(XHostAddress *address)
{
    mSocket->bind(address->getAddress(), address->getPort());

    connect(mSocket, SIGNAL(readyRead()),
            this, SLOT(readPendingDatagrams()));
}

/*-----------------------------------------------------------------+
| Write data to socket
+------------------------------------------------------------------+
| Parameters:
|   data (QByteArray): data to send
|   address (XHostAddress): address/port paring
| Return:
|   success (bool): whether it wrote data out to socket
+-----------------------------------------------------------------*/
bool XUdpSocket::writeData(QByteArray data, XHostAddress *address)
{
    QMutexLocker locker(&mMutex);
    bool success = false;

    qint64 bytesSent = mSocket->writeDatagram(data, address->getAddress(), address->getPort());

    if(data.size() == bytesSent)
    {
        success = true;
        qDebug() << "Sending" << data << "to" << address->getAddress() << ":" << address->getPort();
    }

    return success;
}

/*-----------------------------------------------------------------+
| Read in the data and emit signal with byte array data
+-----------------------------------------------------------------*/
void XUdpSocket::readPendingDatagrams()
{
    QMutexLocker locker(&mMutex);

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
