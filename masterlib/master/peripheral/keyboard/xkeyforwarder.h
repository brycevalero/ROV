#ifndef XKEYFORWARDER_H
#define XKEYFORWARDER_H

#include <QByteArray>
#include <QDebug>
#include <QHostAddress>
#include <QKeyEvent>
#include <QList>
#include <QObject>
#include <QPair>

#include "master/masterlib_global.h"
#include "master/socket/xhostaddress.h"
#include "master/socket/xudpsocket.h"

class MASTERLIBSHARED_EXPORT XKeyForwarder : public QObject
{
    Q_OBJECT

public:
    XKeyForwarder();
    void registerLocal(XHostAddress *address);
    void registerClient(XHostAddress *address);

public slots:
    void sendData(QByteArray bytes);

private:
    QList<XHostAddress*> mHostAddresses;
    XUdpSocket *mUdp;
};

#endif // XKEYFORWARDER_H
