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

bool XTcpClient::connectHost(QHostAddress address, quint16 port)
{
    qDebug() << "Connecting to Host";
    mSocket->connectToHost(address, port);
    return mSocket->waitForConnected();
}

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
