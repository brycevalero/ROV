#ifndef XKEYHANDLER_H
#define XKEYHANDLER_H

#include <QByteArray>
#include <QDebug>
#include <QHash>

#include "master/masterlib_global.h"
#include "master/peripheral/keyboard/xkey.h"

using namespace XKey;

class MASTERLIBSHARED_EXPORT XKeyHandler : public QObject
{
    Q_OBJECT

signals:
    void keyChanged(int key, int byteArrayLen, QByteArray ba);
    void keySet(int keycode, bool state);
    void keySyncFailed();

public:
    XKeyHandler();

public slots:
    void loadKeys(QHash<int, int> *keys);
    bool getKeyByCode(int keycode);
    void setKeyByCode(int keycode, bool state);
    void setKeys(int key, QByteArray bytes);
    QByteArray getKeys();
    void setKey(int key, bool state);
    bool getKey(int key);

private:
    QHash<int,int> *mKeys;
    QByteArray mKeysByteArray;
    int mByteArrayLen;

    bool extractKey(int key, QByteArray bytes);
    void syncKeys(QByteArray bytes);
};

#endif // XKEYHANDLER_H
