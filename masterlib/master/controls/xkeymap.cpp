#include "xkeymap.h"

/*-----------------------------------------------------------------+
| Constructor
+-----------------------------------------------------------------*/
XKeyMap::XKeyMap()
{

}

/*-----------------------------------------------------------------+
| When a key is pressed, this will filter the key press events
| and then emit a signal.  It will ignore any auto repeat key press
| events.
+------------------------------------------------------------------+
| Parameters:
|   obj (QObject): we need the QObject passed in so we can return it
|   event (QEvent): used to filter on
| Return:
|   (bool): whether we filtered the keypress or not
+-----------------------------------------------------------------*/
bool XKeyMap::eventFilter(QObject* obj, QEvent* event)
{
    QKeyEvent* key = static_cast<QKeyEvent*>(event);

    if (event->type()==QEvent::KeyPress) {
        if ( (key->key()==Qt::Key_Enter) || (key->key()==Qt::Key_Return) ) {
            qDebug() << "-----ENTER-------";
        } else {
            return QObject::eventFilter(obj, event);
        }
        return true;
    } else {
        return QObject::eventFilter(obj, event);
    }
    return false;
}
