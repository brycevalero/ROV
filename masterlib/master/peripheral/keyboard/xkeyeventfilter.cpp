#include "xkeyeventfilter.h"

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
bool XKeyEventFilter::eventFilter(QObject* obj, QEvent* event)
{
    if (event->type()==QEvent::KeyPress)
    {
        QKeyEvent* key = static_cast<QKeyEvent*>(event);
        if(!key->isAutoRepeat())
        {
            qDebug() << "pressed" << key->key();
            emit keyEvent(key->key(), true);
            return true;
        }
    }
    else if(event->type()==QEvent::KeyRelease)
    {
        QKeyEvent* key = static_cast<QKeyEvent*>(event);
        if(!key->isAutoRepeat())
        {
            qDebug() << "released" << key->key();
            emit keyEvent(key->key(), false);
            return true;
        }
    }
    else
    {
        return QObject::eventFilter(obj, event);
    }
    return false;
}
