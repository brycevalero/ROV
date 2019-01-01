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
    void navigationLoaded(QHash<int, int> *nav);
    void settingsLoaded(QSettings *settings);
    void settingsSaved(QSettings *settings);

public slots:
    void loadNavigation();
    void loadSettings(QString file);
    void saveSettings();
    void loadGroup(QString group);

private:
    QString mSettingsFile;
    QSettings *mSettings;
    QHash<int, int> *mKeys;
};

#endif // XKEYSETTINGS_H
