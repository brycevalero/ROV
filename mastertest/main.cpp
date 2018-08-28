#include "suite.h"
#include <QDebug>
#include <QtTest/QtTest>

/*-----------------------------------------------------------------+
| Main entry point
+------------------------------------------------------------------+
| Parameters:
|   argc (int)
|   argv (char)
| Return:
|   int
+-----------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    // setup lambda
    int status = 0;
    auto runTest = [&status, argc, argv](QObject* obj) {
        status |= QTest::qExec(obj, argc, argv);
    };

    // run suite
    auto &suite = TestSuite::suite();
    for (auto it = suite.begin(); it != suite.end(); ++it) {
        runTest(*it);
    }
}
