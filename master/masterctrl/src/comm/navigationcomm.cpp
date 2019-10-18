#include "navigationcomm.h"

NavigationComm::NavigationComm(QObject *parent) : QObject(parent)
{
    keySettings = new XKeySettings();
    //keyEventFilter = new XKeyEventFilter();
    keyHandler = new XKeyHandler();
    keyProtocol = new XKeyProtocol();
    udpSocket = new XUdpSocket();

    QObject::connect(keySettings, SIGNAL(navigationLoaded(QHash<int,int>*)), keyHandler, SLOT(loadKeys(QHash<int,int>*)));
    //QObject::connect(this, SIGNAL(keyEvent(int,bool)), keyHandler, SLOT(setKeyByCode(int,bool)));
    QObject::connect(keyHandler, SIGNAL(keyChanged(int,int,QByteArray)), keyProtocol, SLOT(frameData(int,int,QByteArray)));
    QObject::connect(keyProtocol, SIGNAL(dataFramed(QByteArray)), udpSocket, SLOT(writeData(QByteArray)));

    XHostAddress *local = new XHostAddress(QHostAddress::LocalHost, 4000);
    XHostAddress *dest = new XHostAddress(QHostAddress::LocalHost, 8000);

    udpSocket->initSocket(local);
    udpSocket->registerClient(dest);

    keySettings->loadSettings(QDir::currentPath() + "/keys.ini");
    keySettings->loadNavigation();
    keySettings->loadGroup("Navigation");

    //this->installEventFilter(keyEventFilter);
    //this->installEventFilter(this);
}

void NavigationComm::processKey(int key, bool state)
{
    qDebug() << "NavigationComm PROCESSING KEY: " << key;
    keyHandler->setKeyByCode(key, state);
}
