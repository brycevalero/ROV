#include "xkeysettings.h"

/*-----------------------------------------------------------------+
| Constructor
+-----------------------------------------------------------------*/
XKeySettings::XKeySettings()
{
    mKeys = new QHash<int, int>();
    mSettingsFile = "";
    mSettings = NULL;
}

/*-----------------------------------------------------------------+
| Constructor
+-----------------------------------------------------------------*/
XKeySettings::XKeySettings(QString file)
{
    mKeys = new QHash<int, int>();
    mSettingsFile = "";
    mSettings = NULL;
    this->loadSettings(file);
}

/*-----------------------------------------------------------------+
| Destructor
+-----------------------------------------------------------------*/
XKeySettings::~XKeySettings()
{
    delete mSettings;
    delete mKeys;
}

/*-----------------------------------------------------------------+
| Load settings from ini file
+------------------------------------------------------------------+
| Parameters:
|   file (QString): path to ini file
| Return:
|   mSettings (QSettings): loaded settings or null
+-----------------------------------------------------------------*/
QSettings* XKeySettings::loadSettings(QString file)
{
    mSettingsFile = file;
    QFileInfo check_file(mSettingsFile);

    // check if file exists and if yes: Is it really a file and no directory?
    if (check_file.exists() && check_file.isFile()) {
        mSettings = new QSettings(mSettingsFile, QSettings::IniFormat);
        emit settingsLoaded(mSettings);
    }

    return mSettings;
}

/*-----------------------------------------------------------------+
| Save settings to ini file
+------------------------------------------------------------------+
| Return:
|   void
+-----------------------------------------------------------------*/
void XKeySettings::saveSettings()
{
    mSettings->beginGroup("Navigation");
    mSettings->setValue("enter", QKeySequence(Qt::Key_Return));
    mSettings->setValue("forward", QKeySequence(Qt::Key_W));
    mSettings->setValue("reverse", QKeySequence(Qt::Key_S));
    mSettings->setValue("left", QKeySequence(Qt::Key_A));
    mSettings->setValue("right", QKeySequence(Qt::Key_D));
    mSettings->setValue("surface", QKeySequence(Qt::Key_Z));
    mSettings->setValue("dive", QKeySequence(Qt::Key_X));
    mSettings->endGroup();

    emit settingsSaved(mSettings);
}

/*-----------------------------------------------------------------+
| Load navigation from ini file
+------------------------------------------------------------------+
| Return:
|   void
+-----------------------------------------------------------------*/
void XKeySettings::loadNavigation()
{
    mSettings->beginGroup("Navigation");
    int count = 0x00;
    foreach (const QString &key, mSettings->childKeys()) {
        QKeySequence seq = QKeySequence(mSettings->value(key).toString());
        mKeys->insert(seq[0], count);

        qDebug() << "Key Map:" << mSettings->value(key).toString() << seq[0] << ":" << count;
        count++;
    }

    if(mKeys->size() > 0) {
        emit navigationLoaded(mKeys);
    }
    mSettings->endGroup();
}

/*-----------------------------------------------------------------+
| Load specific group of ini file
+------------------------------------------------------------------+
| Parameters:
|   group (QString): section of ini file
| Return:
|   groupMap QMap<QString, QVariant>: group settings
+-----------------------------------------------------------------*/
QMap<QString, QVariant> XKeySettings::loadGroup(QString group)
{
    QMap<QString, QVariant> groupMap;

    if(mSettings->childGroups().contains(group))
    {
        mSettings->beginGroup(group);
        foreach (const QString &key, mSettings->childKeys()) {
            groupMap.insert(key, mSettings->value(key));
        }
        mSettings->endGroup();
    }

    if(groupMap.size() > 0) {
        emit groupLoaded(group, groupMap);
    }

    return groupMap;
}

void XKeySettings::saveGroup(QString group, QMap<QString, QVariant>)
{

}
