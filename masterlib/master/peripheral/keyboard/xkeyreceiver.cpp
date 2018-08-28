#include "xkeyreceiver.h"

/*-----------------------------------------------------------------+
| Constructor
+------------------------------------------------------------------+
| Parameters:
|   none
| Return:
|   none
+-----------------------------------------------------------------*/
XKeyReceiver::XKeyReceiver()
{
    mUdp = new XUdpSocket();
}

/*-----------------------------------------------------------------+
| Register a host to receive data from
+------------------------------------------------------------------+
| Parameters:
|   address (XHostAddress): address/port paring
| Return:
|   (void)
+-----------------------------------------------------------------*/
void XKeyReceiver::registerHost(XHostAddress *address)
{
    mHostAddress=address;
    mUdp->initSocket(address);
    QObject::connect(mUdp, SIGNAL(gotDatagrams(QByteArray)), this, SLOT(receiveData(QByteArray)));
}

/*-----------------------------------------------------------------+
| Receive data from socket
+------------------------------------------------------------------+
| Parameters:
|   data (QByteArray): data to receive
| Return:
|   (void)
+-----------------------------------------------------------------*/
void XKeyReceiver::receiveData(QByteArray ba)
{
    if(ba.startsWith(XKey::HEX_SOH) && ba.endsWith(XKey::HEX_ETX))
    {
        QByteArray payload = ba;
    }
    qDebug() << ba;
    emit dataReceived(ba);
}
