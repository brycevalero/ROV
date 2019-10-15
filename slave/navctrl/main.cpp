#include <QCoreApplication>
#include <QHostAddress>
#include <QByteArray>

#include "master/masterlib.h"
#include "master/ipc/socket/xudpsocket.h"
#include "master/ipc/sharedmem/xsharedmemory.h"
#include "master/config/ini/xkeysettings.h"
#include "master/peripheral/keyboard/xkeyhandler.h"
#include "master/peripheral/keyboard/xkeyprotocol.h"
#include "master/peripheral/keyboard/xkeyeventgenerator.h"
#include "master/peripheral/keyboard/xkeyeventfilter.h"
#include "master/controls/xkeymap.h"
#include "master/controls/xnavigation.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    XKeySettings *keySettings = new XKeySettings();
    XUdpSocket *udpSocket = new XUdpSocket();
    XKeyProtocol *keyProtocol = new XKeyProtocol();
    XKeyHandler *keyHandler = new XKeyHandler();
    XKeyEventGenerator *keyEventGenerator = new XKeyEventGenerator();
    XKeyMap *keyMap = new XKeyMap();
    XNavigation *navigation = new XNavigation();

    //test stuff
    XSharedMemory *sharedMem = new XSharedMemory();
    sharedMem->readMem();

    QObject::connect(keySettings, SIGNAL(settingsLoaded(QSettings*)), keyMap, SLOT(setKeyMap(QSettings*)));
    QObject::connect(keySettings, SIGNAL(navigationLoaded(QHash<int,int>*)), keyHandler, SLOT(loadKeys(QHash<int,int>*)));

    QObject::connect(udpSocket, SIGNAL(gotDatagrams(QByteArray)), keyProtocol, SLOT(extractData(QByteArray)));
    QObject::connect(keyProtocol, SIGNAL(dataExtracted(int, QByteArray)), keyHandler, SLOT(setKeys(int, QByteArray)));
    QObject::connect(keyHandler, SIGNAL(keySet(int,bool)), keyEventGenerator, SLOT(generateEvent(int,bool)));
    QObject::connect(keyMap, SIGNAL(navEvent(QString,bool)), navigation, SLOT(navEvent(QString,bool)));

    XHostAddress *local = new XHostAddress(QHostAddress::LocalHost, 8000);

    //QCoreApplication *app = new QCoreApplication (argc, argv);
    //app.installEventFilter(keyEventFilter);
    app.installEventFilter(keyMap);
    //keySettings->saveSettings();
    keySettings->loadSettings(QDir::currentPath() + "/keys.ini");
    keySettings->loadNavigation();
    keySettings->loadGroup("Navigation");
    udpSocket->initSocket(local);

    return app.exec();
}
