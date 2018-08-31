#include "xkeyforwarder.h"

/*-----------------------------------------------------------------+
| Constructor - creates a new connection for keys to be forwarded
| onto.
+-----------------------------------------------------------------*/
XKeyForwarder::XKeyForwarder()
{
    mUdp = new XUdpSocket();
}

/*-----------------------------------------------------------------+
| Registers an ip address and port for localhost to communicate on
+------------------------------------------------------------------+
| Parameters:
|   address (XHostAddress): an ip and port data type
| Return:
|   void
+-----------------------------------------------------------------*/
void XKeyForwarder::registerLocal(XHostAddress *address)
{
    mUdp->initSocket(address);
}

/*-----------------------------------------------------------------+
| Registers an ip address and port for remote machine to
| communicate with
+------------------------------------------------------------------+
| Parameters:
|   address (XHostAddress): an ip and port data type
| Return:
|   void
+-----------------------------------------------------------------*/
void XKeyForwarder::registerClient(XHostAddress *address)
{
    mHostAddresses.append(address);
}

/*-----------------------------------------------------------------+
| Writes data to remote address over socket
+------------------------------------------------------------------+
| Parameters:
|   bytes (QByteArray): data to be sent in array of bytes
| Return:
|   void
+-----------------------------------------------------------------*/
void XKeyForwarder::sendData(QByteArray bytes)
{
    for(int i=0; i<mHostAddresses.size(); i++)
    {
        mUdp->writeData(bytes, mHostAddresses.at(i));
    }
}
