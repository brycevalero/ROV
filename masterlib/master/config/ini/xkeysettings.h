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
    XKeySettings(QString file);
    ~XKeySettings();

signals:
    void navigationLoaded(QHash<int, int> *nav);
    void settingsLoaded(QSettings *settings);
    void settingsSaved(QSettings *settings);
    void groupLoaded(QString group, QMap<QString, QVariant>);

public slots:
    QSettings* loadSettings(QString file);
    void saveSettings();
    void loadNavigation();
    QMap<QString, QVariant> loadGroup(QString group);
    void saveGroup(QString group, QMap<QString, QVariant> groupMap);

private:
    QString mSettingsFile;
    QSettings *mSettings;
    QHash<int, int> *mKeys;
};

#endif // XKEYSETTINGS_H
