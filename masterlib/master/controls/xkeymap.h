#ifndef XKEYMAP_H
#define XKEYMAP_H

#include <QByteArray>
#include <QDebug>
#include <QHash>

#include "master/masterlib_global.h"
#include "master/peripheral/keyboard/xkey.h"

using namespace XKey;

class MASTERLIBSHARED_EXPORT XKeyMap : public QObject
{
    Q_OBJECT

public:
    XKeyMap();

public slots:
    void sendKey(int keycode, bool state);

private:
    QHash<int,int> mKeys;
    QByteArray mKeysByteArray;
};

#endif // XKEYMAP_H
