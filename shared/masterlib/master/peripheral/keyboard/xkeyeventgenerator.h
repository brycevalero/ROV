#ifndef XKEYEVENTGENERATOR_H
#define XKEYEVENTGENERATOR_H

#include <QDebug>
#include <QGuiApplication>
#include <QKeyEvent>
#include <QObject>

#include "master/masterlib_global.h"

class MASTERLIBSHARED_EXPORT XKeyEventGenerator : public QObject
{
    Q_OBJECT

public:
    XKeyEventGenerator();

public slots:
    void generateEvent(int keycode, bool state);
};

#endif // XKEYEVENTGENERATOR_H
