#include "testkeyprotocol.h"

void TestKeyProtocol::randomizeData()
{
    int high =10;
    int low =0;
    mKey = qrand() % ((high + 1) - low) + low;
    mPayload.clear();
    mPayload.append(QRandomGenerator64::global()->generate64());
    mCRC = mKeyProtocol->calculateCRC(mPayload);

    QByteArray data;
    data.append(XKey::HEX_SOH);
    data.append(0x4B); //KEY (letter k)
    data.append(mKey);
    data.append(0x4C); //Length (letter L)
    data.append(mPayload.length());
    data.append(XKey::HEX_STX);
    data.append(mPayload);
    data.append(mCRC);
    data.append(XKey::HEX_ETX);

    mData = data;
}

/*-----------------------------------------------------------------+
| Initialize test case variables
+------------------------------------------------------------------+
| Parameters:
|   none
| Return:
|   (void)
+-----------------------------------------------------------------*/
void TestKeyProtocol::initTestCase()
{
    mKeyProtocol = new XKeyProtocol();
}

/*-----------------------------------------------------------------+
| Test the constructor
+------------------------------------------------------------------+
| Parameters:
|   none
| Return:
|   (void)
+-----------------------------------------------------------------*/
void TestKeyProtocol::testConstructor()
{

}

void TestKeyProtocol::testCalculateCRC()
{
    QBENCHMARK {
        this->randomizeData();
        quint16 crc = qChecksum(mPayload.data(), mPayload.length());

        QCOMPARE(mCRC, crc);
    }
}

void TestKeyProtocol::testFrameData()
{
    QBENCHMARK {
        QSignalSpy spy(mKeyProtocol, SIGNAL(dataFramed(QByteArray)));

        this->randomizeData();
        QByteArray returned = mKeyProtocol->frameData(mKey, mPayload.length(), mPayload);

        // make sure the signal was emitted exactly one time
        QCOMPARE(spy.count(), 1);
        // take the first signal
        QList<QVariant> arguments = spy.takeFirst();

        QVERIFY(arguments.at(0).type() == QVariant::ByteArray);
        QCOMPARE(arguments.at(0).toByteArray(), mData);
        QCOMPARE(returned, mData);
    }
}

void TestKeyProtocol::testExtractData()
{
    QSignalSpy spy(mKeyProtocol, SIGNAL(dataExtracted(int,QByteArray)));

    this->randomizeData();
    mKeyProtocol->extractData(mData);

    QCOMPARE(spy.count(), 1); // make sure the signal was emitted exactly one time
    QList<QVariant> arguments = spy.takeFirst(); // take the first signal

    QVERIFY(arguments.at(0).type() == QVariant::Int);
    QVERIFY(arguments.at(1).type() == QVariant::ByteArray);

    QCOMPARE(arguments.at(0).toInt(), mKey);
    QCOMPARE(arguments.at(1).toByteArray(), mPayload);
}

static TestKeyProtocol TEST_KEYPROTOCOL;
