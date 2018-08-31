#include "xkeyprotocol.h"

/*-----------------------------------------------------------------+
| Constructor
+-----------------------------------------------------------------*/
XKeyProtocol::XKeyProtocol()
{

}

/*-----------------------------------------------------------------+
| Calculate checksum of payload for protocol
+------------------------------------------------------------------+
| Parameters:
|   payload (QByteArray): keys as a byte array
| Return:
|   crc (quint16): the checksum
+-----------------------------------------------------------------*/
quint16 XKeyProtocol::calculateCRC(QByteArray payload)
{
    quint16 crc = qChecksum(payload.data(), payload.length());
    qDebug() << crc;

    return crc;
}

/*-----------------------------------------------------------------+
| Wraps our key byte array (our payload) into a functional protocol.
| To make things easier to parse on receiving side of our protocol,
| we will send the index of the key that changed along with the
| payload. The protocol will take the form of:
| SOH K Index STX payload CRC ETX
+------------------------------------------------------------------+
| Parameters:
|   key (int): index of key within byte array
|   payload (QByteArray): state of all keys
| Return:
|   (QByteArray)
+-----------------------------------------------------------------*/
QByteArray XKeyProtocol::frameData(int key, int payloadLen, QByteArray payload)
{
    quint16 crc = calculateCRC(payload);

    QByteArray data;
    data.append(XKey::HEX_SOH);
    data.append(0x4B); //letter K
    data.append(key);
    data.append(0x4C); //letter L
    data.append(payloadLen);
    data.append(XKey::HEX_STX);
    data.append(payload);
    data.append(crc);
    data.append(XKey::HEX_ETX);

    emit dataFramed(data);
    return data;
}

/*-----------------------------------------------------------------+
| Extracts data from protocol
+------------------------------------------------------------------+
| Parameters:
|   data (QByteArray): keys as a byte array
| Return:
|   (void)
+-----------------------------------------------------------------*/
void XKeyProtocol::extractData(QByteArray data)
{
    int key = NULL;

    if(data.startsWith(XKey::HEX_SOH)
            && data.contains(0x4B)
            && data.contains(XKey::HEX_STX)
            && data.endsWith(XKey::HEX_ETX))
    {
        key = data.at(2);
        data = data.mid(4,4);

        emit dataExtracted(key, data);
    }
}
