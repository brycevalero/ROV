#include "xtcpserver.h"

/*-----------------------------------------------------------------+
| Constructor
+------------------------------------------------------------------+
| Parameters:
|   none
| Return:
|   none
+-----------------------------------------------------------------*/
XTcpServer::XTcpServer(QObject *parent):
    QObject(parent)
{
    mServer = new QTcpServer(this);
}

bool XTcpServer::listen(QHostAddress address, quint16 port)
{
    connect(mServer, SIGNAL(newConnection()),
            this, SLOT(pendingConnection()));

    bool listening = mServer->listen(address, port);

    if(listening)
    {
        qDebug() << "Server started";
    }
    else
    {
        qDebug() << "Server error!";
    }

    return listening;
}

void XTcpServer::pendingConnection()
{
    // need to grab the socket
    QTcpSocket *socket = mServer->nextPendingConnection();
    connect(socket, SIGNAL(readyRead()), this, SLOT(readData()));

    qDebug() << "Made a connection";
}

void XTcpServer::readData()
{
    qDebug() << "Reading data";

    QTcpSocket *socket = static_cast<QTcpSocket*>(sender());
    QByteArray buffer;

    while (socket->bytesAvailable() > 0)
    {
        buffer.append(socket->readAll());
    }

    if(!buffer.isEmpty())
    {
        qDebug() << "Emitting got data";

        emit gotData(buffer);
        buffer.clear();
    }


    socket->write("Hello client\r\n");
    socket->flush();

    socket->waitForBytesWritten(3000);

    socket->close();
    qDebug() << "Closed";
}
