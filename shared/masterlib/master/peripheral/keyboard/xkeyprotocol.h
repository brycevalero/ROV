#ifndef XKEYPROTOCOL_H
#define XKEYPROTOCOL_H

#include <QDebug>
#include <QObject>

#include "master/masterlib_global.h"

class MASTERLIBSHARED_EXPORT XKeyProtocol : public QObject
{
    Q_OBJECT

signals:
    void dataFramed(QByteArray data);
    void dataExtracted(int key, QByteArray payload);

public:
    enum Control{
        HEX_NULL=0x00,
        HEX_SOH=0x01,
        HEX_STX=0x02,
        HEX_ETX=0x03,
        HEX_EOT=0x04,
        HEX_DLE=0x10
    };
    XKeyProtocol();
    quint16 calculateCRC(QByteArray payload);

public slots:
    QByteArray frameData(int key, int payloadLen, QByteArray payload);
    void extractData(QByteArray data);

};

#endif // XKEYPROTOCOL_H
