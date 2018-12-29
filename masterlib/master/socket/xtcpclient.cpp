#include "xtcpclient.h"

/*-----------------------------------------------------------------+
| Constructor
+------------------------------------------------------------------+
| Parameters:
|   parent (QObject): parent object
+-----------------------------------------------------------------*/
XTcpClient::XTcpClient(QObject *parent):
    QObject(parent)
{
    mSocket = new QTcpSocket(this);
}

/*-----------------------------------------------------------------+
| Connect to a host
+------------------------------------------------------------------+
| Parameters:
|   address (QHostAddress): an address
|   port (quint16): a port
| Return:
|   (bool): connected
+-----------------------------------------------------------------*/
bool XTcpClient::connectHost(QHostAddress address, quint16 port)
{
    qDebug() << "Connecting to Host";
    mSocket->connectToHost(address, port);
    return mSocket->waitForConnected();
}

bool XTcpClient::readData()
{
    //TODO: implement
    return true;
}

/*-----------------------------------------------------------------+
| Write data to the socket
+------------------------------------------------------------------+
| Parameters:
|   data (QByteArray): byte array of data
| Return:
|   (bool): written
+-----------------------------------------------------------------*/
bool XTcpClient::writeData(QByteArray data)
{
    QMutexLocker locker(&mMutex);
    bool success = false;

    //if we are connected, write and wait till finished
    if(mSocket->state() == QAbstractSocket::ConnectedState)
    {
        qDebug() << "Writing Data";
        mSocket->write(data);
        success = mSocket->waitForBytesWritten();
    }

    return success;
}
