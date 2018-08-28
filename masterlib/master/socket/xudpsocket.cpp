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

/*-----------------------------------------------------------------+
| Bind to a socket at specific address/port
+------------------------------------------------------------------+
| Parameters:
|   address (XHostAddress): address/port paring
| Return:
|   (void)
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
|   (void)
+-----------------------------------------------------------------*/
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

/*-----------------------------------------------------------------+
| Read in the data to byte array
+------------------------------------------------------------------+
| Parameters:
|   none
| Return:
|   (void)
+-----------------------------------------------------------------*/
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
