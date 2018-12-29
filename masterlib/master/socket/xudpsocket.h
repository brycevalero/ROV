#ifndef XUDPSOCKET_H
#define XUDPSOCKET_H

#include <QMutex>
#include <QMutexLocker>
#include <QObject>
#include <QUdpSocket>

#include "master/masterlib_global.h"
#include "master/socket/xhostaddress.h"

class MASTERLIBSHARED_EXPORT XUdpSocket: public QObject
{
    Q_OBJECT
public:
    explicit XUdpSocket(QObject *parent = 0);
    void initSocket(XHostAddress *address);
    void registerClient(XHostAddress *address);

signals:
    void gotDatagrams(QByteArray datagram);

public slots:
    void readPendingDatagrams();
    bool writeData(QByteArray data);
    bool writeData(QByteArray data, XHostAddress *address);

private:
    QMutex mMutex;
    QUdpSocket *mSocket;
    QList<XHostAddress*> mHostAddresses;
};

#endif // XUDPSOCKET_H
