#include "xsharedmemory.h"

XSharedMemory::XSharedMemory()
{
    //we have to set the key in order to create or attach
    mSharedMem.setKey("EXAMPLESHAREDMEM");
}

void XSharedMemory::writeMem()
{

    int mSize = 1000;
    QBuffer buffer;
    buffer.open(QBuffer::ReadWrite);
    buffer.write("LALALALLLAA");

    if (!mSharedMem.create(mSize)) {
        qDebug() << "Unable to create shared memory segment.";
        return;
    }

    mSharedMem.lock();
    char *to = (char*)mSharedMem.data();
    const char *from = buffer.data().data();
    memcpy(to, from, qMin(mSharedMem.size(), mSize));
    mSharedMem.unlock();

    emit wroteMemory();
}

void XSharedMemory::readMem()
{
    QByteArray tmp;
    if (!mSharedMem.attach()) {
        return;
    }

    QBuffer buffer;
    QDataStream in(&buffer);
    QString image;

    mSharedMem.lock();
    buffer.setData((char*)mSharedMem.constData(), mSharedMem.size());
    buffer.open(QBuffer::ReadOnly);
    in >> image;
    mSharedMem.unlock();

    mSharedMem.detach();

    qDebug() << "SHARED MEMORY DATA: " << image;


    return;
}
