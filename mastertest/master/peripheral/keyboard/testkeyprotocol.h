#ifndef TESTKEYPROTOCOL_H
#define TESTKEYPROTOCOL_H

#include <QtTest/QtTest>

#include "suite.h"
#include "master/peripheral/keyboard/xkeyprotocol.h"

class TestKeyProtocol: public TestSuite
{
    Q_OBJECT

public:
    using TestSuite::TestSuite;

private slots:
    void testFromUtf8();
    void testToUtf8();
};

#endif // TESTKEYPROTOCOL_H
