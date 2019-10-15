#ifndef XSHAREDMEMORY_H
#define XSHAREDMEMORY_H

#include <QBuffer>
#include <QDataStream>
#include <QDebug>
#include <QObject>
#include <QSharedMemory>

#include "master/masterlib_global.h"

class MASTERLIBSHARED_EXPORT  XSharedMemory : public QObject
{
    Q_OBJECT

public:
    XSharedMemory();

signals:
    void wroteMemory();
    void readMemory();

public slots:
    void writeMem();
    void readMem();

private:
    QSharedMemory mSharedMem;
};

#endif // XSHAREDMEMORY_H
