#ifndef TESTHOSTADDRESS_H
#define TESTHOSTADDRESS_H

#include <QtTest/QtTest>
#include <QHostAddress>

#include "suite.h"
#include "master/ipc/socket/xhostaddress.h"

class TestHostAddress: public TestSuite
{
    Q_OBJECT

public:
    using TestSuite::TestSuite;

private slots:
    void initTestCase();
    void testConstructor();
    void testGetAddress();
    void testSetAddress();
    void testGetPort();
    void testSetPort();
    void cleanupTestCase();

private:
    XHostAddress *mHostAddress;
};

#endif // TESTHOSTADDRESS_H
