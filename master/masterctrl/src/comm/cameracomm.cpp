#include "cameracomm.h"

CameraComm::CameraComm(QObject *parent) : QObject(parent)
{

}

void CameraComm::processKey(int key, bool state)
{
    qDebug() << "CameraComm PROCESSING KEY: " << key;
}
