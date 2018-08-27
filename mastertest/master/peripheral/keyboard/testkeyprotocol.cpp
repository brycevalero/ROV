#include "testkeyprotocol.h"

/*-----------------------------------------------------------------+
| Constructor
+------------------------------------------------------------------+
| Parameters:
|   none
| Return:
|   none
+-----------------------------------------------------------------*/
void TestKeyProtocol::testFromUtf8()
{
    std::string str("Hello");
    auto qstr = QString::fromUtf8(str.data());
    QCOMPARE(qstr, QString("Hello"));
}

/*-----------------------------------------------------------------+
| Constructor
+------------------------------------------------------------------+
| Parameters:
|   none
| Return:
|   none
+-----------------------------------------------------------------*/
void TestKeyProtocol::testToUtf8()
{
    QString qstr("Hello");
    std::string str(qstr.toUtf8().data());
    QCOMPARE(str, std::string("Hello"));
}

static TestKeyProtocol TEST_KEYPROTOCOL;
