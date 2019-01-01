#include "xkeysettings.h"

/*-----------------------------------------------------------------+
| Constructor
+-----------------------------------------------------------------*/
XKeySettings::XKeySettings()
{
    mSettingsFile = "";
    mSettings = NULL;
    mKeys = new QHash<int, int>();
}

/*-----------------------------------------------------------------+
| Load settings from ini file
+------------------------------------------------------------------+
| Parameters:
|   file (QString): path to ini file
| Return:
|   void
+-----------------------------------------------------------------*/
void XKeySettings::loadSettings(QString file)
{
    mSettingsFile = file;
    QFileInfo check_file(mSettingsFile);

    // check if file exists and if yes: Is it really a file and no directory?
    if (check_file.exists() && check_file.isFile()) {
        mSettings = new QSettings(mSettingsFile, QSettings::IniFormat);
        emit settingsLoaded(mSettings);
    }
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

void XKeySettings::loadGroup(QString group)
{
    //TODO: load settings generically by group and emit qmap
/*
    if(mSettings->childGroups().contains(group)){
        mSettings->beginGroup(group);
        QMap group = new QMap();
        int count = 0x00;
        foreach (const QString &key, mSettings->childKeys()) {
            QKeySequence seq = QKeySequence(mSettings->value(key).toString());
            qDebug() << "Key Map:" << mSettings->value(key).toString() << seq[0] << ":" << count;
            count++;
        }
        mSettings->endGroup();
    }*/
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
