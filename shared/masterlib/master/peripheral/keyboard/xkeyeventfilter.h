#ifndef XKEYEVENTFILTER_H
#define XKEYEVENTFILTER_H

#include <QDebug>
#include <QKeyEvent>
#include <QObject>

#include "master/masterlib_global.h"

class MASTERLIBSHARED_EXPORT XKeyEventFilter : public QObject
{
    Q_OBJECT

signals:
    void keyEvent(int key, bool state);
    void keyPressed(int key);
    void keyReleased(int key);

protected:
    bool eventFilter(QObject* obj, QEvent* event);
};

#endif // XKEYEVENTFILTER_H
