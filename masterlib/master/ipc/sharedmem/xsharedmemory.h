#ifndef XSHAREDMEMORY_H
#define XSHAREDMEMORY_H

#include <QBuffer>
#include <QDebug>
#include <QSharedMemory>

#include "master/masterlib_global.h"

class MASTERLIBSHARED_EXPORT  XSharedMemory
{
public:
    XSharedMemory();

private:
    QSharedMemory mSharedMem;
};

#endif // XSHAREDMEMORY_H
