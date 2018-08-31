#include "xkeymap.h"

/*-----------------------------------------------------------------+
| Constructor
+-----------------------------------------------------------------*/
XKeyMap::XKeyMap()
{

}

/*-----------------------------------------------------------------+
| Map a particular keycode to an action
+------------------------------------------------------------------+
| Parameters:
|   keycode (int): qt enum of key
|   state (bool): on (pressed) or off (released)
| Return:
|   void
+-----------------------------------------------------------------*/
void XKeyMap::sendKey(int keycode, bool state)
{
    qDebug() << "YEAH" << keycode;

    switch( keycode )
    {
        case Qt::Key_Up:
            qDebug() << "UP";
            break ;
        case Qt::Key_Down :
            qDebug() << "DOWN";
            break ;
        case Qt::Key_Left :
            qDebug() << "LEFT";
            break ;
        case Qt::Key_Right :
            qDebug() << "RIGHT";
            break ;
    }
}
