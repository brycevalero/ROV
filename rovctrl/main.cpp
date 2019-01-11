#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QHostAddress>
#include <QByteArray>
#include <QObject>

#include "master/masterlib.h"
#include "master/ipc/socket/xudpsocket.h"
#include "master/config/ini/xkeysettings.h"
#include "master/peripheral/keyboard/xkeyeventfilter.h"
#include "master/peripheral/keyboard/xkeyhandler.h"
#include "master/peripheral/keyboard/xkeyprotocol.h"

int main(int argc, char *argv[])
{
    XKeySettings *keySettings = new XKeySettings();
    XKeyEventFilter *keyEventFilter = new XKeyEventFilter();
    XKeyHandler *keyHandler = new XKeyHandler();
    XKeyProtocol *keyProtocol = new XKeyProtocol();
    XUdpSocket *udpSocket = new XUdpSocket();

    QObject::connect(keySettings, SIGNAL(navigationLoaded(QHash<int,int>*)), keyHandler, SLOT(loadKeys(QHash<int,int>*)));
    QObject::connect(keyEventFilter, SIGNAL(keyEvent(int,bool)), keyHandler, SLOT(setKeyByCode(int,bool)));
    QObject::connect(keyHandler, SIGNAL(keyChanged(int,int,QByteArray)), keyProtocol, SLOT(frameData(int,int,QByteArray)));
    QObject::connect(keyProtocol, SIGNAL(dataFramed(QByteArray)), udpSocket, SLOT(writeData(QByteArray)));

    XHostAddress *local = new XHostAddress(QHostAddress::LocalHost, 4000);
    XHostAddress *dest = new XHostAddress(QHostAddress::LocalHost, 8000);

    udpSocket->initSocket(local);
    udpSocket->registerClient(dest);

#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    //qmlRegisterType<MainWindow>("com.mycompany.qmlcomponents", 1, 0, "MainWindow");

    QGuiApplication app(argc, argv);
    app.installEventFilter(keyEventFilter);

    //keySettings->saveSettings();
    keySettings->loadSettings(QDir::currentPath() + "/keys.ini");
    keySettings->loadNavigation();
    keySettings->loadGroup("Navigation");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
