#ifndef NAVIGATIONCOMM_H
#define NAVIGATIONCOMM_H

#include <QDebug>
#include <QObject>

#include "master/masterlib.h"
#include "master/ipc/sharedmem/xsharedmemory.h"
#include "master/ipc/socket/xudpsocket.h"
#include "master/config/ini/xkeysettings.h"
#include "master/peripheral/keyboard/xkeyeventfilter.h"
#include "master/peripheral/keyboard/xkeyhandler.h"
#include "master/peripheral/keyboard/xkeyprotocol.h"

class NavigationComm : public QObject
{
    Q_OBJECT
public:
    explicit NavigationComm(QObject *parent = nullptr);

public slots:
    void processKey(int key, bool state);

private:
    XKeySettings *keySettings;
    XKeyEventFilter *keyEventFilter;
    XKeyHandler *keyHandler;
    XKeyProtocol *keyProtocol;
    XUdpSocket *udpSocket;

};

#endif // NAVIGATIONCOMM_H
