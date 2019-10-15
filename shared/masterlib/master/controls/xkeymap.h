#ifndef XKEYMAP_H
#define XKEYMAP_H

#include <QDebug>
#include <QKeyEvent>
#include <QObject>
#include <QSettings>

#include "master/masterlib_global.h"

class MASTERLIBSHARED_EXPORT XKeyMap : public QObject
{
    Q_OBJECT

public:
    XKeyMap();

signals:
    void navEvent(QString command, bool active);

public slots:
    void setKeyMap(QSettings *settings);

protected:
    bool eventFilter(QObject* obj, QEvent* event);

private:
    QHash<QString,QString> mKeyMap;

};

#endif // XKEYMAP_H
