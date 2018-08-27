#ifndef XKEYPROTOCOL_H
#define XKEYPROTOCOL_H

#include <QDebug>
#include <QObject>

#include "master/masterlib_global.h"
#include "master/peripheral/keyboard/xkey.h"

using namespace XKey;

class MASTERLIBSHARED_EXPORT XKeyProtocol : public QObject
{
    Q_OBJECT

signals:
    void dataFramed(QByteArray data);
    void dataExtracted(int key, QByteArray payload);

public:
    XKeyProtocol();
    quint16 calculateCRC(QByteArray payload);

public slots:
    QByteArray frameData(int key, int payloadLen, QByteArray payload);
    void extractData(QByteArray data);

};

#endif // XKEYPROTOCOL_H
