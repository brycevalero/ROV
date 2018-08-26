#ifndef XKEYSETTINGS_H
#define XKEYSETTINGS_H

#include <QDebug>
#include <QDir>
#include <QObject>
#include <QSettings>

#include "master/masterlib_global.h"

class MASTERLIBSHARED_EXPORT XKeySettings : public QObject
{
    Q_OBJECT
public:
    XKeySettings();

signals:

public slots:
    void loadSettings();
    void saveSettings();

private:
    QString mKeySettingsFile;

};

#endif // XKEYSETTINGS_H
