#ifndef XTCPCLIENT_H
#define XTCPCLIENT_H

#include <QHostAddress>
#include <QMutex>
#include <QMutexLocker>
#include <QObject>
#include <QTcpSocket>

#include "master/masterlib_global.h"

class MASTERLIBSHARED_EXPORT XTcpClient: public QObject
{
    Q_OBJECT
public:
    explicit XTcpClient(QObject *parent = 0);

signals:

public slots:
    bool connectHost(QHostAddress address, quint16 port);
    bool readData();
    bool writeData(QByteArray data);

private:
    QMutex mMutex;
    QTcpSocket *mSocket;
};

#endif // XTCPCLIENT_H
