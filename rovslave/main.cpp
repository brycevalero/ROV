#include <QCoreApplication>
#include <QHostAddress>
#include <QByteArray>

#include "master/masterlib.h"
#include "master/socket/xudpsocket.h"
#include "master/config/ini/xkeysettings.h"
#include "master/peripheral/keyboard/xkeyhandler.h"
#include "master/peripheral/keyboard/xkeyprotocol.h"
#include "master/peripheral/keyboard/xkeyreceiver.h"
#include "master/peripheral/keyboard/xkeyeventgenerator.h"
#include "master/peripheral/keyboard/xkeyeventfilter.h"
#include "master/controls/xkeymap.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    XKeySettings *keySettings = new XKeySettings();
    XHostAddress *dest = new XHostAddress(QHostAddress::LocalHost, 8000);
    XKeyReceiver *keyReceiver = new XKeyReceiver();
    XKeyProtocol *keyProtocol = new XKeyProtocol();
    XKeyHandler *keyHandler = new XKeyHandler();
    XKeyEventGenerator *keyEventGenerator = new XKeyEventGenerator();
    XKeyEventFilter *keyEventFilter = new XKeyEventFilter();
    XKeyMap *keyMap = new XKeyMap();
    keyReceiver->registerHost(dest);

    QObject::connect(keyReceiver, SIGNAL(dataReceived(QByteArray)), keyProtocol, SLOT(extractData(QByteArray)));
    QObject::connect(keyProtocol, SIGNAL(dataExtracted(int, QByteArray)), keyHandler, SLOT(setKeys(int, QByteArray)));
    QObject::connect(keyHandler, SIGNAL(keySet(int,bool)), keyEventGenerator, SLOT(generateEvent(int,bool)));
    QObject::connect(keyEventFilter, SIGNAL(keyEvent(int,bool)), keyMap, SLOT(sendKey(int,bool)));

    //QCoreApplication *app = new QCoreApplication (argc, argv);
    app.installEventFilter(keyEventFilter);

    return app.exec();
}
