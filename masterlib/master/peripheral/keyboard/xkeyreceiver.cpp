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

void XKeyReceiver::registerHost(XHostAddress *address)
{
    mHostAddress=address;
    mUdp->initSocket(address);
    QObject::connect(mUdp, SIGNAL(gotDatagrams(QByteArray)), this, SLOT(receiveData(QByteArray)));
}

void XKeyReceiver::receiveData(QByteArray ba)
{
    if(ba.startsWith(XKey::HEX_SOH) && ba.endsWith(XKey::HEX_ETX))
    {

        QByteArray payload = ba;


    }
    qDebug() << ba;
    emit dataReceived(ba);
}
