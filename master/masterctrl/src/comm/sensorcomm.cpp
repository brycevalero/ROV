#include "sensorcomm.h"

SensorComm::SensorComm(QObject *parent) : QObject(parent)
{
    m_online = false;
}

bool SensorComm::online() const
{
    return m_online;
}

void SensorComm::setOnline(bool online)
{
    if (m_online == online)
        return;

    m_online = online;
    emit onlineChanged(m_online);
}
