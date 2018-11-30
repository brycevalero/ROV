#ifndef XKEYSETTINGS_H
#define XKEYSETTINGS_H

#include <QDebug>
#include <QDir>
#include <QKeySequence>
#include <QObject>
#include <QSettings>

#include "master/masterlib_global.h"
#include "master/controls/xnavigation.h"

class MASTERLIBSHARED_EXPORT XKeySettings : public QObject
{
    Q_OBJECT
public:
    XKeySettings();

signals:
    void settingsLoaded(QSettings *settings);
    void settingsSaved(QSettings *settings);

public slots:
    void loadSettings();
    void saveSettings();

private:
    QString mKeySettingsFile;
    QSettings *mSettings;

};

#endif // XKEYSETTINGS_H
