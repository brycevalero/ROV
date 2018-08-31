#include "xkeyhandler.h"

/*-----------------------------------------------------------------+
| Constructor - correlates a key enum to a bit index for each key
+-----------------------------------------------------------------*/
XKeyHandler::XKeyHandler()
{
    mKeys[Qt::Key_Escape]=XKey::Key_Escape;
    mKeys[Qt::Key_Tab]=XKey::Key_Tab;
    mKeys[Qt::Key_Backtab]=XKey::Key_Backtab;
    mKeys[Qt::Key_Backspace]=XKey::Key_Backspace;
    mKeys[Qt::Key_Return]=XKey::Key_Return;
    mKeys[Qt::Key_Enter]=XKey::Key_Enter;
    mKeys[Qt::Key_Insert]=XKey::Key_Insert;
    mKeys[Qt::Key_Delete]=XKey::Key_Delete;
    mKeys[Qt::Key_Pause]=XKey::Key_Pause;
    mKeys[Qt::Key_Print]=XKey::Key_Print;
    mKeys[Qt::Key_SysReq]=XKey::Key_SysReq;
    mKeys[Qt::Key_Clear]=XKey::Key_Clear;
    mKeys[Qt::Key_Home]=XKey::Key_Home;
    mKeys[Qt::Key_End]=XKey::Key_End;
    mKeys[Qt::Key_Left]=XKey::Key_Left;
    mKeys[Qt::Key_Up]=XKey::Key_Up;
    mKeys[Qt::Key_Right]=XKey::Key_Right;
    mKeys[Qt::Key_Down]=XKey::Key_Down;
    mKeys[Qt::Key_PageUp]=XKey::Key_PageUp;
    mKeys[Qt::Key_PageDown]=XKey::Key_PageDown;
    mKeys[Qt::Key_Shift]=XKey::Key_Shift;
    mKeys[Qt::Key_Control]=XKey::Key_Control;
    mKeys[Qt::Key_Meta]=XKey::Key_Meta;
    mKeys[Qt::Key_Alt]=XKey::Key_Alt;
    mKeys[Qt::Key_CapsLock]=XKey::Key_CapsLock;
    mKeys[Qt::Key_NumLock]=XKey::Key_NumLock;
    mKeys[Qt::Key_ScrollLock]=XKey::Key_ScrollLock;
    mKeys[Qt::Key_F1]=XKey::Key_F1;
    mKeys[Qt::Key_F2]=XKey::Key_F2;
    mKeys[Qt::Key_F3]=XKey::Key_F3;
    mKeys[Qt::Key_F4]=XKey::Key_F4;
    mKeys[Qt::Key_F5]=XKey::Key_F5;
    mKeys[Qt::Key_F6]=XKey::Key_F6;
    mKeys[Qt::Key_F7]=XKey::Key_F7;
    mKeys[Qt::Key_F8]=XKey::Key_F8;
    mKeys[Qt::Key_F9]=XKey::Key_F9;
    mKeys[Qt::Key_F10]=XKey::Key_F10;
    mKeys[Qt::Key_F11]=XKey::Key_F11;
    mKeys[Qt::Key_F12]=XKey::Key_F12;
    /*mKeys[Qt::Key_F13]=XKey::Key_F13;
    mKeys[Qt::Key_F14]=XKey::Key_F14;
    mKeys[Qt::Key_F15]=XKey::Key_F15;
    mKeys[Qt::Key_F16]=XKey::Key_F16;
    mKeys[Qt::Key_F17]=XKey::Key_F17;
    mKeys[Qt::Key_F18]=XKey::Key_F18;
    mKeys[Qt::Key_F19]=XKey::Key_F19;
    mKeys[Qt::Key_F20]=XKey::Key_F20;
    mKeys[Qt::Key_F21]=XKey::Key_F21;
    mKeys[Qt::Key_F22]=XKey::Key_F22;
    mKeys[Qt::Key_F23]=XKey::Key_F23;
    mKeys[Qt::Key_F24]=XKey::Key_F24;
    mKeys[Qt::Key_F25]=XKey::Key_F25;
    mKeys[Qt::Key_F26]=XKey::Key_F26;
    mKeys[Qt::Key_F27]=XKey::Key_F27;
    mKeys[Qt::Key_F28]=XKey::Key_F28;
    mKeys[Qt::Key_F29]=XKey::Key_F29;
    mKeys[Qt::Key_F30]=XKey::Key_F30;
    mKeys[Qt::Key_F31]=XKey::Key_F31;
    mKeys[Qt::Key_F32]=XKey::Key_F32;
    mKeys[Qt::Key_F33]=XKey::Key_F33;
    mKeys[Qt::Key_F34]=XKey::Key_F34;
    mKeys[Qt::Key_F35]=XKey::Key_F35;*/

    mKeysByteArray.resize(mKeys.size()/8+1);

    for(int j=0;j<mKeysByteArray.size();j++){
        mKeysByteArray[j]=0x00;
    }

    mByteArrayLen = mKeysByteArray.size();
    qDebug() << "BYTE ARRAY LEN" << mByteArrayLen;
}

/*-----------------------------------------------------------------+
| Gets the state of a key by keycode
+------------------------------------------------------------------+
| Parameters:
|   keycode (int): qt enum of key
| Return:
|   (bool): get bit, on (pressed) or off (released)
+-----------------------------------------------------------------*/
bool XKeyHandler::getKeyByCode(int keycode)
{
    return extractKey(mKeys[keycode], mKeysByteArray);
}

/*-----------------------------------------------------------------+
| Sets the state of a key by keycode
+------------------------------------------------------------------+
| Parameters:
|   keycode (int): qt enum of key
|   state (bool): set bit to be on (pressed) or off (released)
| Return:
|   void
+-----------------------------------------------------------------*/
void XKeyHandler::setKeyByCode(int keycode, bool state)
{
    setKey(mKeys[keycode], state);
}

/*-----------------------------------------------------------------+
| Sets the state of all keypresses within a byte array
+------------------------------------------------------------------+
| Parameters:
|   key (int): index of key within byte array
|   bytes (QByteArray): state of all keys
| Return:
|   void
+-----------------------------------------------------------------*/
void XKeyHandler::setKeys(int key, QByteArray bytes)
{
    //sometimes we will set keys with a null key index
    if(key != NULL)
    {
        //grab the state of key from passed in byte array
        bool state = extractKey(key, bytes);
        //then set key state of our local byte array
        setKey(key, state);
        //notify everyone we got new key value
        emit keySet(mKeys.key(key), state);
        qDebug() << "KEYS:" << key << state;
    }

    syncKeys(bytes);
}

/*-----------------------------------------------------------------+
| Gets the state of all keypresses within a byte array
+------------------------------------------------------------------+
| Return:
|   mKeysByteArray (QByteArray): state of all keys
+-----------------------------------------------------------------*/
QByteArray XKeyHandler::getKeys()
{
    return mKeysByteArray;
}

/*-----------------------------------------------------------------+
| Sets the state of a single keypress within a byte array
+------------------------------------------------------------------+
| Parameters:
|   key (int): index of key within byte array
|   state (bool): set bit to be on (pressed) or off (released)
| Return:
|   void
+-----------------------------------------------------------------*/
void XKeyHandler::setKey(int key, bool state)
{
    //get our byte index, each byte has 8 bits
    int byteIndex = key/8;
    //get our bit index within byte
    int bitIndex = key%8;

    //extract a byte of data that has bit we want to change
    char byte = mKeysByteArray.at(byteIndex);

    //set the state of that single bit in byte
    if(state){
        //To set a bit:
        byte |= 1 << bitIndex;
    } else {
        //To clear a bit:
        byte &= ~(1 << bitIndex);
    }

    //push updated byte back into byte array
    mKeysByteArray[byteIndex]=byte;

    //emit that one or more keys has changed
    emit keyChanged(key, mByteArrayLen, mKeysByteArray);
}

/*-----------------------------------------------------------------+
| Gets a state of a single key within a byte array
+------------------------------------------------------------------+
| Parameters:
|   key (int): index of key within byte array
| Return:
|   (bool): bit state is on (pressed) or off (released)
+-----------------------------------------------------------------*/
bool XKeyHandler::getKey(int key)
{
    return extractKey(key, mKeysByteArray);
}

/*-----------------------------------------------------------------+
| Gets a state of a single key within a byte array
+------------------------------------------------------------------+
| Parameters:
|   key (int): index of key within byte array
|   bytes (QByteArray): state of all keys
| Return:
|   (bool): bit state is on (pressed) or off (released)
+-----------------------------------------------------------------*/
bool XKeyHandler::extractKey(int key, QByteArray bytes)
{
    //get our byte index, each byte has 8 bits
    int byteIndex = key/8;
    //get our bit index within byte
    int bitIndex = key%8;

    //extract a byte of data that has bit we want to change
    char byte = bytes.at(byteIndex);

    //return the state of our bit of interest as a bool
    return ((byte >> bitIndex) & 1);
}

/*-----------------------------------------------------------------+
| Ensures local key byte array matches passed in byte array
+------------------------------------------------------------------+
| Parameters:
|   bytes (QByteArray): state of all keys
| Return:
|   void
+-----------------------------------------------------------------*/
void XKeyHandler::syncKeys(QByteArray bytes)
{
    //if there is still a mismatch between our old and new byte arrays,
    //lets make sure to sync data
    QByteArray tmp = mKeysByteArray;
    mKeysByteArray=bytes;

    if(tmp != mKeysByteArray)
    {
        qDebug() << "Mismatch of key byte arrays, lets sync up!";

        for(int j=0;j<mKeysByteArray.size();j++)
        {
            if(tmp.at(j) != mKeysByteArray.at(j))
            {
                //extract a byte of data that has bit we want to change
                char byte1 = mKeysByteArray.at(j);
                char byte2 = tmp.at(j);

                for(int k=0;k<8;k++)
                {
                    bool newVal =((byte1 >> k) & 1);
                    bool oldVal =((byte2 >> k) & 1);

                    if(oldVal!=newVal)
                    {
                        //notify everyone we got new key value
                        emit keySet(mKeys.key(j*8+k), newVal);
                        qDebug() << j*8+k << newVal;
                    }
                }
            }
        }
    }

    if(tmp != mKeysByteArray)
    {
        emit keySyncFailed();
    }
}


