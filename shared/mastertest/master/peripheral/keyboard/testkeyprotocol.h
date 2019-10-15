#ifndef TESTKEYPROTOCOL_H
#define TESTKEYPROTOCOL_H

#include <QtTest/QtTest>
#include <QRandomGenerator64>

#include "suite.h"
#include "master/peripheral/keyboard/xkeyprotocol.h"

class TestKeyProtocol: public TestSuite
{
    Q_OBJECT

public:
    using TestSuite::TestSuite;

private:
    XKeyProtocol *mKeyProtocol;
    quint8 mKey;
    QByteArray mPayload;
    QByteArray mData;
    quint16 mCRC;

    void randomizeData();

private slots:
    void initTestCase();
    void testConstructor();
    void testCalculateCRC();
    void testFrameData();
    void testExtractData();



};

#endif // TESTKEYPROTOCOL_H
