#include "testhostaddress.h"

/*-----------------------------------------------------------------+
| Initialize test case variables
+------------------------------------------------------------------+
| Parameters:
|   none
| Return:
|   (void)
+-----------------------------------------------------------------*/
void TestHostAddress::initTestCase()
{
    mHostAddress = new XHostAddress(QHostAddress::LocalHost, 8000);
}

/*-----------------------------------------------------------------+
| Test the constructor
+------------------------------------------------------------------+
| Parameters:
|   none
| Return:
|   (void)
+-----------------------------------------------------------------*/
void TestHostAddress::testConstructor()
{
    QVERIFY(mHostAddress->getAddress() == QHostAddress::LocalHost);
    QVERIFY(mHostAddress->getPort() == 8000);
}

/*-----------------------------------------------------------------+
| Initialize test case variables
+------------------------------------------------------------------+
| Parameters:
|   none
| Return:
|   (void)
+-----------------------------------------------------------------*/
void TestHostAddress::testGetAddress()
{
    QVERIFY(mHostAddress->getAddress() == QHostAddress::LocalHost);
}

void TestHostAddress::testSetAddress()
{
    mHostAddress->setAddress(QHostAddress::LocalHostIPv6);
    QVERIFY(mHostAddress->getAddress() == QHostAddress::LocalHostIPv6);
}

void TestHostAddress::testGetPort()
{
    QVERIFY(mHostAddress->getPort() == 8000);
}

void TestHostAddress::testSetPort()
{
    mHostAddress->setPort(5678);
    QVERIFY(mHostAddress->getPort() == 5678);
}

void TestHostAddress::cleanupTestCase()
{
    delete mHostAddress;
}

static TestHostAddress TEST_HOSTADDRESS;
