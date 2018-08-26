#ifndef XNAVIGATION_H
#define XNAVIGATION_H

#include <QDebug>
#include <QObject>

#include "master/masterlib_global.h"

class MASTERLIBSHARED_EXPORT XNavigation : public QObject
{
    Q_OBJECT

public:
    XNavigation();

public slots:
    void navFoward();
    void navReverse();
    void navRight();
    void navLeft();
    void navSurface();
    void navDive();
};

#endif // XNAVIGATION_H
