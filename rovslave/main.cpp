#include <QCoreApplication>
#include <QHostAddress>
#include <QByteArray>

#include "master/masterlib.h"
#include "master/socket/xudpsocket.h"
#include "master/config/ini/xkeysettings.h"
#include "master/peripheral/keyboard/xkeyhandler.h"
#include "master/peripheral/keyboard/xkeyprotocol.h"
#include "master/peripheral/keyboard/xkeyeventgenerator.h"
#include "master/peripheral/keyboard/xkeyeventfilter.h"
#include "master/controls/xkeymap.h"

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

    QObject::connect(keySettings, SIGNAL(settingsSaved(QSettings*)), keyMap, SLOT(setKeyMap(QSettings*)));
    QObject::connect(udpSocket, SIGNAL(gotDatagrams(QByteArray)), keyProtocol, SLOT(extractData(QByteArray)));
    QObject::connect(keyProtocol, SIGNAL(dataExtracted(int, QByteArray)), keyHandler, SLOT(setKeys(int, QByteArray)));
    QObject::connect(keyHandler, SIGNAL(keySet(int,bool)), keyEventGenerator, SLOT(generateEvent(int,bool)));
    QObject::connect(keyMap, SIGNAL(navEvent(QString,bool)), navigation, SLOT(navEvent(QString,bool)));

    XHostAddress *local = new XHostAddress(QHostAddress::LocalHost, 8000);

    //QCoreApplication *app = new QCoreApplication (argc, argv);
    //app.installEventFilter(keyEventFilter);
    app.installEventFilter(keyMap);
    keySettings->saveSettings();
    udpSocket->initSocket(local);

    return app.exec();
}
