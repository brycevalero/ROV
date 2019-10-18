#include "maincomm.h"

MainComm::MainComm()
{
    m_camera = new CameraComm();
    m_navigation = new NavigationComm();
    m_sensors = new SensorComm();

    m_cameraEventFilter = new CameraEventFilter();
    m_navigationEventFilter = new NavigationEventFilter();

    //Last event filter added here is the first one processed.
    //This means navigation takes precedence
    this->installEventFilter(m_cameraEventFilter);
    this->installEventFilter(m_navigationEventFilter);

    m_camera->moveToThread(&m_cameraThread);
    connect(m_cameraEventFilter, &CameraEventFilter::keyEvent, m_camera, &CameraComm::processKey);
    m_cameraThread.start();

    m_navigation->moveToThread(&m_navigationThread);
    connect(m_navigationEventFilter, &NavigationEventFilter::keyEvent, m_navigation, &NavigationComm::processKey);
    m_navigationThread.start();
}

CameraComm *MainComm::camera() const
{
    return m_camera;
}

NavigationComm *MainComm::navigation() const
{
    return m_navigation;
}

SensorComm *MainComm::sensors() const
{
    return m_sensors;
}

void MainComm::setCamera(CameraComm *camera)
{
    if (m_camera == camera)
        return;

    m_camera = camera;
    emit cameraChanged(m_camera);
}

void MainComm::setNavigation(NavigationComm *navigation)
{
    if (m_navigation == navigation)
        return;

    m_navigation = navigation;
    emit navigationChanged(m_navigation);
}

void MainComm::setSensors(SensorComm *sensors)
{
    if (m_sensors == sensors)
        return;

    m_sensors = sensors;
    emit sensorsChanged(m_sensors);
}
