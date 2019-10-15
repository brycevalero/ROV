#include "xkeysettings.h"

/*-----------------------------------------------------------------+
| Constructor
+-----------------------------------------------------------------*/
XKeySettings::XKeySettings()
{
    mGroups.append("Navigation");
    mKeys = new QHash<int, int>();
    mSettingsFile = "";
    mSettings = NULL;
}

/*-----------------------------------------------------------------+
| Constructor
+-----------------------------------------------------------------*/
XKeySettings::XKeySettings(QString file)
{
    mGroups.append("Navigation");
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

void XKeySettings::defaultSettings()
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
    this->saveSettings();
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
    bool isFile = false;
    bool hasGroups = true;
    mSettingsFile = file;
    mSettings = new QSettings(mSettingsFile, QSettings::IniFormat);
    QFileInfo check_file(mSettingsFile);
    qDebug() << "Load settings";

    // check if file exists and if yes: Is it really a file and not directory?
    if (check_file.exists() && check_file.isFile())
    {
        qDebug() << "File exists";
        isFile = true;
    }

    //ensure we have all the groups we care about before emitting
    //settingsLoaded signal
    for (const auto& i : mGroups)
    {
        qDebug() << "Check: " << i;
        if(!mSettings->childGroups().contains(i))
        {
            qDebug() << "Not Contains: " << i;
            hasGroups = false;
            break;
        }
    }

    // if we fail to read file or expected groups, load defaults
    if(!isFile || !hasGroups)
    {
        qDebug() << "Still not loaded";
        this->defaultSettings();
    }

    emit settingsLoaded(mSettings);
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
    mSettings->sync();
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
    foreach (const QString &key, mSettings->childKeys())
    {
        QKeySequence seq = QKeySequence(mSettings->value(key).toString());
        mKeys->insert(seq[0], count);

        qDebug() << "Key Map:" << mSettings->value(key).toString() << seq[0] << ":" << count;
        count++;
    }

    if(mKeys->size() > 0)
    {
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

        foreach (const QString &key, mSettings->childKeys())
        {
            groupMap.insert(key, mSettings->value(key));
        }

        mSettings->endGroup();
    }

    if(groupMap.size() > 0)
    {
        emit groupLoaded(group, groupMap);
    }

    return groupMap;
}

/*-----------------------------------------------------------------+
| Save specific group to ini file
+------------------------------------------------------------------+
| Parameters:
|   group (QString): section of ini file
|   groupMap QMap<QString, QVariant>: group settings
+-----------------------------------------------------------------*/
void XKeySettings::saveGroup(QString group, QMap<QString, QVariant> groupMap)
{
    QMap<QString, QVariant>::const_iterator i = groupMap.constBegin();
    mSettings->beginGroup(group);

    while (i != groupMap.constEnd())
    {
        mSettings->setValue(i.key(), i.value());
        ++i;
    }

    mSettings->endGroup();
    mSettings->sync();
    emit groupSaved(group);
}

/*-----------------------------------------------------------------+
| Remove specific group from ini file
+------------------------------------------------------------------+
| Parameters:
|   group (QString): section of ini file
+-----------------------------------------------------------------*/
void XKeySettings::removeGroup(QString group)
{
    mSettings->remove(group);
    mSettings->sync();
    emit groupRemoved(group);
}
