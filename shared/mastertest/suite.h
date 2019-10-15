#pragma once

#include <QObject>
#include <vector>

class TestSuite: public QObject
{
public:
     TestSuite();
     static std::vector<QObject*> & suite();
};
