#include "xkeymap.h"

/*-----------------------------------------------------------------+
| Constructor
+-----------------------------------------------------------------*/
XKeyMap::XKeyMap()
{

}

/*-----------------------------------------------------------------+
| Reverses ini file key value pairs for easier access from
| event filter
+------------------------------------------------------------------+
| Parameters:
|   QSettings: pointer to settings object
+-----------------------------------------------------------------*/
void XKeyMap::setKeyMap(QSettings *settings)
{
    settings->beginGroup("Navigation");
    foreach (const QString &key, settings->childKeys()) {
        mKeyMap[settings->value(key).toString()] = key;
    }
    settings->endGroup();
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
    QString seqKey = QKeySequence(key->key()).toString();

    if (event->type()==QEvent::KeyPress) {
        if ( mKeyMap.contains(seqKey)){
            //example: "dive", true
            emit navEvent(mKeyMap[seqKey], true);
        }else {
            return QObject::eventFilter(obj, event);
        }
    } else {
        if ( mKeyMap.contains(seqKey)){
            //example: "dive", false
            emit navEvent(mKeyMap[seqKey], false);
        }else {
            return QObject::eventFilter(obj, event);
        }
    }
    return true;
}
