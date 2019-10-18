#ifndef QMLTYPEREGISTRAR_H
#define QMLTYPEREGISTRAR_H

#include <QCoreApplication>
#include <QObject>
#include <QQmlEngine>

#include "src/comm/maincomm.h"
#include "src/comm/cameracomm.h"
#include "src/comm/navigationcomm.h"
#include "src/comm/sensorcomm.h"

class QmlTypeRegistrar : public QObject
{
    Q_OBJECT
public:
    explicit QmlTypeRegistrar(QObject *parent = nullptr);
    static QObject *getNavigationComm(QQmlEngine *engine, QJSEngine *scriptEngine);

signals:

public slots:

private:

};

#endif // QMLTYPEREGISTRAR_H
