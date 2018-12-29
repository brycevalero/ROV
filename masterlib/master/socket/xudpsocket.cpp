/*-----------------------------------------------------------------+
| Purpose:
|   A UDP socket is used for connectionless will read from any client that sends datagrams on the
|   right port.  In order to write data
| Author:
|   Bryce Valero
+-----------------------------------------------------------------*/
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
| Bind to a specific address/port to listen on
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
| Registers an address/port to send datagrams to
+------------------------------------------------------------------+
| Parameters:
|   address (XHostAddress): an ip and port data type
| Return:
|   void
+-----------------------------------------------------------------*/
void XUdpSocket::registerClient(XHostAddress *address)
{
    mHostAddresses.append(address);
}

/*-----------------------------------------------------------------+
| Write data to all registered addresses/ports
+------------------------------------------------------------------+
| Parameters:
|   data (QByteArray): data to send
| Return:
|   success (bool): whether it wrote data out to ALL sockets
+-----------------------------------------------------------------*/
bool XUdpSocket::writeData(QByteArray data)
{
    bool success=true;

    for(int i=0; i<mHostAddresses.size(); i++)
    {
        if(!this->writeData(data, mHostAddresses.at(i)))
        {
            success=false;
        }
    }

    return success;
}

/*-----------------------------------------------------------------+
| Write data to a specific address/port
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
| Read in the data from any client that sends data to this UDP
| socket and emit signal with datagrams
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
