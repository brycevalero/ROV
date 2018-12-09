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
    data.append(0x4B); //KEY (letter k)
    data.append(key);
    data.append(0x4C); //Length (letter L)
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
    int len = NULL;
    QByteArray crcBytes = NULL;
    QByteArray ctrlBytes = NULL;
    QByteArray payload = NULL;

    if(data.startsWith(XKey::HEX_SOH)
            && data.contains(0x4B)
            && data.contains(XKey::HEX_STX)
            && data.endsWith(XKey::HEX_ETX))
    {
        key = data.at(2);
        len = data.at(4);

        payload = data.mid(6,len);
        crcBytes = data.mid(6 + payload.length(), 1);
        ctrlBytes.append(calculateCRC(payload));

        qDebug() << "EXTRACTED DATA: " << payload.toHex() << "CRC: " << crcBytes.toHex() << ctrlBytes.toHex();

        if(crcBytes == ctrlBytes){
            emit dataExtracted(key, payload);
        }
    }
}
