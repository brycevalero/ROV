#include "xkeyhandler.h"

/*-----------------------------------------------------------------+
| Constructor - correlates a key enum to a bit index for each key
+-----------------------------------------------------------------*/
XKeyHandler::XKeyHandler()
{
    mKeys = new QHash<int, int>();
    //mKeysByteArray = new QByteArray();
    mByteArrayLen = 0;
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
    bool success = false;
    if (mKeys->contains(keycode)){
        success = extractKey(mKeys->value(keycode), mKeysByteArray);
    }
    return success;
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
    bool success = false;
    if (mKeys->contains(keycode)){
        setKey(mKeys->value(keycode), state);
        success = true;
    }
    //return success;
}

/*-----------------------------------------------------------------+
| Loads keys and creates a bytearray to hold individual key state
+------------------------------------------------------------------+
| Parameters:
|   keys (QHash<int, int>):
+-----------------------------------------------------------------*/
void XKeyHandler::loadKeys(QHash<int, int> *keys)
{
    mKeys = keys;

    mKeysByteArray.resize(mKeys->size()/8+1);

    for(int j=0;j<mKeysByteArray.size();j++){
        mKeysByteArray[j]=0x00;
    }

    mByteArrayLen = mKeysByteArray.size();
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

        qDebug() << "SET KEYs:" << mKeys->key(key) << "VALUE:" << key << "STATE: " << state;

        //notify everyone we got new key value
        emit keySet(mKeys->key(key), state);
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
                        emit keySet(mKeys->key(j*8+k), newVal);
                        //qDebug() << j*8+k << newVal;
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


