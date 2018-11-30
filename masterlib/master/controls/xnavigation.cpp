#include "xnavigation.h"

/*-----------------------------------------------------------------+
| Constructor
+-----------------------------------------------------------------*/
XNavigation::XNavigation()
{

}

void XNavigation::navEvent(QString command, bool active)
{
    qDebug() << "NAV EVENT: " << command << "ACTIVE: " << active;

    if(command == "enter"){
        navDive();
    }
}

void XNavigation::navFoward()
{
    qDebug() << "NavForward";
}

void XNavigation::navReverse()
{
    qDebug() << "NavReverse";
}

void XNavigation::navLeft()
{
    qDebug() << "NavLeft";
}

void XNavigation::navRight()
{
    qDebug() << "NavRight";
}

void XNavigation::navSurface()
{
    qDebug() << "NavSurface";
}

void XNavigation::navDive()
{
    qDebug() << "NavDive";
}



