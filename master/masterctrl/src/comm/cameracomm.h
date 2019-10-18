#ifndef CAMERACOMM_H
#define CAMERACOMM_H

#include <QDebug>
#include <QObject>

class CameraComm: public QObject
{
    Q_OBJECT

public:
    explicit CameraComm(QObject *parent = nullptr);

public slots:
    void processKey(int key, bool state);
};

#endif // CAMERACOMM_H
