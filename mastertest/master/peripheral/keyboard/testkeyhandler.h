#ifndef TESTKEYHANDLER_H
#define TESTKEYHANDLER_H

#include <QtTest/QtTest>

#include "suite.h"
#include "master/peripheral/keyboard/xkeyhandler.h"

class TestKeyHandler: public TestSuite
{
    Q_OBJECT

public:
    using TestSuite::TestSuite;

private slots:
    void initTestCase();
    void testConstructor();
    void cleanupTestCase();

private:
    XKeyHandler *mKeyHandler;
};

#endif // TESTKEYHANDLER_H
