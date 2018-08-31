#include "xkeysettings.h"

/*-----------------------------------------------------------------+
| Constructor
+-----------------------------------------------------------------*/
XKeySettings::XKeySettings()
{
    mKeySettingsFile = QDir::currentPath() + "/keys.ini";

    qDebug() << mKeySettingsFile;
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
    QSettings settings(mKeySettingsFile, QSettings::IniFormat);

}

/*-----------------------------------------------------------------+
| Save settings to ini file
+------------------------------------------------------------------+
| Return:
|   void
+-----------------------------------------------------------------*/
void XKeySettings::saveSettings()
{
    QSettings settings(mKeySettingsFile, QSettings::IniFormat);
    settings.beginGroup("Navigation");
    settings.setValue("up", "llll");
    settings.setValue("down", "lsdkf");
    settings.setValue("left", "lsdkf");
    settings.setValue("right", "lsdkf");
    settings.endGroup();
}
