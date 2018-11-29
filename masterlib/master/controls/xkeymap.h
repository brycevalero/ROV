#ifndef XKEYMAP_H
#define XKEYMAP_H

#include <QDebug>
#include <QKeyEvent>
#include <QObject>

#include "master/masterlib_global.h"

class MASTERLIBSHARED_EXPORT XKeyMap : public QObject
{
    Q_OBJECT

public:
    XKeyMap();

protected:
    bool eventFilter(QObject* obj, QEvent* event);
};

#endif // XKEYMAP_H
