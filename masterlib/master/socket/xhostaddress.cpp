#include "xhostaddress.h"

/*-----------------------------------------------------------------+
| Constructor
+------------------------------------------------------------------+
| Parameters:
|   none
| Return:
|   none
+-----------------------------------------------------------------*/
XHostAddress::XHostAddress()
{
    mHostAddress = NULL;
    mPort = NULL;
}

XHostAddress::XHostAddress(QHostAddress address, quint16 port)
{
    mHostAddress = address;
    mPort = port;
}

QHostAddress XHostAddress::getAddress()
{
    return mHostAddress;
}

void XHostAddress::setAddress(QHostAddress address)
{
    mHostAddress=address;
}

quint16 XHostAddress::getPort()
{
    return mPort;
}

void XHostAddress::setPort(quint16 port)
{
    mPort=port;
}
