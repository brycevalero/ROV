#ifndef MAINCOMM_H
#define MAINCOMM_H

#include <QObject>
#include <QQuickItem>
#include <QThread>

#include "src/comm/cameracomm.h"
#include "src/comm/navigationcomm.h"
#include "src/comm/sensorcomm.h"
#include "src/events/cameraeventfilter.h"
#include "src/events/navigationeventfilter.h"

class MainComm : public QQuickItem
{
    Q_OBJECT

    Q_PROPERTY(CameraComm *camera READ camera WRITE setCamera NOTIFY cameraChanged)
    Q_PROPERTY(NavigationComm *navigation READ navigation WRITE setNavigation NOTIFY navigationChanged)
    Q_PROPERTY(SensorComm *sensors READ sensors WRITE setSensors NOTIFY sensorsChanged)

public:
    MainComm();
    CameraComm * camera() const;
    NavigationComm * navigation() const;
    SensorComm * sensors() const;

signals:
    void cameraChanged(CameraComm * camera);
    void navigationChanged(NavigationComm * navigation);
    void sensorsChanged(SensorComm * sensors);
    void newEvent(QObject *watched, QEvent *event);

public slots:
    void setCamera(CameraComm * camera);
    void setNavigation(NavigationComm * navigation);
    void setSensors(SensorComm * sensors);

private:
    CameraComm * m_camera;
    NavigationComm * m_navigation;
    SensorComm * m_sensors;
    QThread m_cameraThread;
    QThread m_navigationThread;
    QThread m_sensorThread;
    CameraEventFilter * m_cameraEventFilter;
    NavigationEventFilter * m_navigationEventFilter;
};

#endif // MAINCOMM_H
