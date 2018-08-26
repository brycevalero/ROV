#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QHostAddress>
#include <QByteArray>
#include <QObject>

#include "master/masterlib.h"
#include "master/socket/xudpsocket.h"
#include "master/peripheral/keyboard/xkeyeventfilter.h"
#include "master/peripheral/keyboard/xkeyhandler.h"
#include "master/peripheral/keyboard/xkeyprotocol.h"
#include "master/peripheral/keyboard/xkeyforwarder.h"

int main(int argc, char *argv[])
{
    XKeyEventFilter *keyEventFilter = new XKeyEventFilter();
    XKeyHandler *keyHandler = new XKeyHandler();
    XKeyProtocol *keyProtocol = new XKeyProtocol();
    XKeyForwarder *keyForwarder = new XKeyForwarder();

    QObject::connect(keyEventFilter, SIGNAL(keyEvent(int,bool)), keyHandler, SLOT(setKeyByCode(int,bool)));
    QObject::connect(keyHandler, SIGNAL(keyChanged(int,int,QByteArray)), keyProtocol, SLOT(frameData(int,int,QByteArray)));
    QObject::connect(keyProtocol, SIGNAL(dataFramed(QByteArray)), keyForwarder, SLOT(sendData(QByteArray)));

    XHostAddress *local = new XHostAddress(QHostAddress::LocalHost, 4000);
    XHostAddress *dest = new XHostAddress(QHostAddress::LocalHost, 8000);
    keyForwarder->registerLocal(local);
    keyForwarder->registerClient(dest);

#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);
    app.installEventFilter(keyEventFilter);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
