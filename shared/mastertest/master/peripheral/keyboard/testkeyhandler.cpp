#include "testkeyhandler.h"

/*-----------------------------------------------------------------+
| Initialize test case variables
+------------------------------------------------------------------+
| Parameters:
|   none
| Return:
|   (void)
+-----------------------------------------------------------------*/
void TestKeyHandler::initTestCase()
{
    mKeyHandler = new XKeyHandler();
}

/*-----------------------------------------------------------------+
| Test the constructor
+------------------------------------------------------------------+
| Parameters:
|   none
| Return:
|   (void)
+-----------------------------------------------------------------*/
void TestKeyHandler::testConstructor()
{
    //QVERIFY(mHostAddress->getAddress() == QHostAddress::LocalHost);
    //QVERIFY(mHostAddress->getPort() == 8000);
}

void TestKeyHandler::cleanupTestCase()
{
    delete mKeyHandler;
}

static TestKeyHandler TEST_KEYHANDLER;
