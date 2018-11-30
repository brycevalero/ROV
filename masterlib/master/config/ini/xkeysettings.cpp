#include "xkeysettings.h"

/*-----------------------------------------------------------------+
| Constructor
+-----------------------------------------------------------------*/
XKeySettings::XKeySettings()
{
    mKeySettingsFile = QDir::currentPath() + "/keys.ini";
    mSettings = new QSettings(mKeySettingsFile, QSettings::IniFormat);
    saveSettings();
}

/*-----------------------------------------------------------------+
| Load settings from ini file
+------------------------------------------------------------------+
| Return:
|   void
+-----------------------------------------------------------------*/
void XKeySettings::loadSettings()
{
    QFileInfo check_file(mKeySettingsFile);

    // check if file exists and if yes: Is it really a file and no directory?
    if (check_file.exists() && check_file.isFile()) {

        emit settingsLoaded(mSettings);
    }
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
