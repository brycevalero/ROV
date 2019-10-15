#ifndef XHOSTADDRESS_H
#define XHOSTADDRESS_H

#include <QHostAddress>
#include <QObject>

#include "master/masterlib_global.h"

class MASTERLIBSHARED_EXPORT XHostAddress : public QObject
{
    Q_OBJECT

public:
    XHostAddress();
    XHostAddress(QHostAddress address, quint16 port);
    QHostAddress getAddress();
    void setAddress(QHostAddress address);
    quint16 getPort();
    void setPort(quint16 port);

private:
    QHostAddress mHostAddress;
    quint16 mPort;
};

#endif // XHOSTADDRESS_H
