/*-----------------------------------------------------------------+
| Purpose:
|   Pairs a QHostAddress and quint16 port into a single object
| Author:
|   Bryce Valero
+-----------------------------------------------------------------*/
#include "xhostaddress.h"

/*-----------------------------------------------------------------+
| Constructor
+-----------------------------------------------------------------*/
XHostAddress::XHostAddress()
{
    mHostAddress = NULL;
    mPort = NULL;
}

/*-----------------------------------------------------------------+
| Constructor
+------------------------------------------------------------------+
| Parameters:
|   address (QHostAddress): an address
|   port (quint16): a port
+-----------------------------------------------------------------*/
XHostAddress::XHostAddress(QHostAddress address, quint16 port)
{
    mHostAddress = address;
    mPort = port;
}

/*-----------------------------------------------------------------+
| Get address
+------------------------------------------------------------------+
| Return:
|   (QHostAddress)
+-----------------------------------------------------------------*/
QHostAddress XHostAddress::getAddress()
{
    return mHostAddress;
}

/*-----------------------------------------------------------------+
| Set address
+------------------------------------------------------------------+
| Parameters:
|   address (QHostAddress): an address
+-----------------------------------------------------------------*/
void XHostAddress::setAddress(QHostAddress address)
{
    mHostAddress=address;
}

/*-----------------------------------------------------------------+
| Get port
+------------------------------------------------------------------+
| Return:
|   (quint16)
+-----------------------------------------------------------------*/
quint16 XHostAddress::getPort()
{
    return mPort;
}

/*-----------------------------------------------------------------+
| Set port
+------------------------------------------------------------------+
| Parameters:
|   port (quint16): a port
+-----------------------------------------------------------------*/
void XHostAddress::setPort(quint16 port)
{
    mPort=port;
}
