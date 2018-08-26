#ifndef XTCPSERVER_H
#define XTCPSERVER_H

#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>
#include <QDebug>

#include "master/masterlib_global.h"

class MASTERLIBSHARED_EXPORT XTcpServer: public QObject
{
    Q_OBJECT
public:
    explicit XTcpServer(QObject *parent = 0);

public slots:
    bool listen(QHostAddress address, quint16 port);

signals:
    void gotData(QByteArray data);

private slots:
    void pendingConnection();
    void readData();

private:
    QTcpServer *mServer;
    QTcpSocket *mClient;
};

#endif // XTCPSERVER_H
