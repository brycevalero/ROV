#include "xkeyeventgenerator.h"

/*-----------------------------------------------------------------+
| Constructor
+------------------------------------------------------------------+
| Parameters:
|   none
| Return:
|   none
+-----------------------------------------------------------------*/
XKeyEventGenerator::XKeyEventGenerator()
{

}

/*-----------------------------------------------------------------+
| Generate a keyboard event
+------------------------------------------------------------------+
| Parameters:
|   keycode (int): qt enum of key
|   state (bool): on (pressed) or off (released)
| Return:
|   void
+-----------------------------------------------------------------*/
void XKeyEventGenerator::generateEvent(int keycode, bool state)
{
    QKeyEvent *keyEvent;

    if(state)
    {
        keyEvent = new QKeyEvent(QEvent::KeyPress,keycode,Qt::NoModifier);
    }
    else
    {
        keyEvent = new QKeyEvent(QEvent::KeyRelease,keycode,Qt::NoModifier);
    }

    QGuiApplication::postEvent(this, keyEvent);
}
