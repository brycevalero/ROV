#include "qmltyperegistrar.h"


QmlTypeRegistrar::QmlTypeRegistrar(QObject *parent) : QObject(parent)
{
    qmlRegisterType<MainComm>("registered.comm", 1, 0, "MainComm");
    qmlRegisterType<NavigationComm>("registered.comm", 1, 0, "NavigationComm");
    //qmlRegisterSingletonType<EventFilter>("com.brycevalero.rov", 1, 0, "NavigationComm", getNavigationComm);
}

QObject *QmlTypeRegistrar::getNavigationComm(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    NavigationComm *navyComm = new NavigationComm();
    return navyComm;
}
