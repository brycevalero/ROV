#include "suite.h"

/*-----------------------------------------------------------------+
| Constructor
+------------------------------------------------------------------+
| Parameters:
|   none
| Return:
|   none
+-----------------------------------------------------------------*/
TestSuite::TestSuite()
{
    suite().push_back(this);
}

/*-----------------------------------------------------------------+
| Handle to all our test objects
+------------------------------------------------------------------+
| Parameters:
|   none
| Return:
|   std::vector<QObject*>
+-----------------------------------------------------------------*/
std::vector<QObject*> & TestSuite::suite()
{
    static std::vector<QObject*> objects;
    return objects;
}
