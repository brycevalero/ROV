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

/*-----------------------------------------------------------------+
| Constructor
+------------------------------------------------------------------+
| Parameters:
|   address (QHostAddress): an address
|   port (quint16): a port
| Return:
|   none
+-----------------------------------------------------------------*/
XHostAddress::XHostAddress(QHostAddress address, quint16 port)
{
    mHostAddress = address;
    mPort = port;
}

/*-----------------------------------------------------------------+
| Get address
+------------------------------------------------------------------+
| Parameters:
|   none
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
| Return:
|   (void)
+-----------------------------------------------------------------*/
void XHostAddress::setAddress(QHostAddress address)
{
    mHostAddress=address;
}

/*-----------------------------------------------------------------+
| Get port
+------------------------------------------------------------------+
| Parameters:
|   none
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
| Return:
|   (void)
+-----------------------------------------------------------------*/
void XHostAddress::setPort(quint16 port)
{
    mPort=port;
}
