#ifndef SENSORCOMM_H
#define SENSORCOMM_H

#include <QObject>

class SensorComm: public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool online READ online WRITE setOnline NOTIFY onlineChanged)

public:
    explicit SensorComm(QObject *parent = nullptr);
    bool online() const;

public slots:
    void setOnline(bool online);

signals:
    void onlineChanged(bool online);

private:
    bool m_online;
};

#endif // SENSORCOMM_H
