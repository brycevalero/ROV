#include "xsharedmemory.h"

XSharedMemory::XSharedMemory()
{
    //we have to set the key in order to create or attach
    mSharedMem.setKey("EXAMPLESHAREDMEM");
    int mSize = 1000;
    QBuffer buffer;

    if (!mSharedMem.create(mSize)) {
        qDebug() << "Unable to create shared memory segment.";
        return;
    }

    mSharedMem.lock();
    char *to = (char*)mSharedMem.data();
    const char *from = buffer.data().data();
    memcpy(to, from, qMin(mSharedMem.size(), mSize));
    mSharedMem.unlock();
}
