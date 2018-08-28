#include "xtcpclient.h"

/*-----------------------------------------------------------------+
| Constructor
+------------------------------------------------------------------+
| Parameters:
|   none
| Return:
|   none
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
    qDebug() << "Writing Data";
    if(mSocket->state() == QAbstractSocket::ConnectedState)
    {
        //mSocket->write(IntToArray(data.size()));
        mSocket->write(data); //write the data itself
        return mSocket->waitForBytesWritten();
    }
    else
    {
        return false;
    }
}
