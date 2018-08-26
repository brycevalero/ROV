#ifndef XKEYRECEIVER_H
#define XKEYRECEIVER_H

#include <QByteArray>
#include <QDebug>
#include <QObject>

#include "master/masterlib_global.h"
#include "master/peripheral/keyboard/xkey.h"
#include "master/socket/xhostaddress.h"
#include "master/socket/xudpsocket.h"

using namespace XKey;

class MASTERLIBSHARED_EXPORT XKeyReceiver : public QObject
{
    Q_OBJECT

signals:
    void dataReceived(QByteArray payload);

public:
    XKeyReceiver();
    void registerHost(XHostAddress *address);

public slots:
    void receiveData(QByteArray ba);

private:
    XHostAddress *mHostAddress;
    XUdpSocket *mUdp;
    QByteArray mKeysByteArray;

};

#endif // XKEYRECEIVER_H
