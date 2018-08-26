#include "xkeysettings.h"

/*-----------------------------------------------------------------+
| Constructor
+------------------------------------------------------------------+
| Parameters:
|   none
| Return:
|   none
+-----------------------------------------------------------------*/
XKeySettings::XKeySettings()
{
    mKeySettingsFile = QDir::currentPath() + "/keys.ini";

    qDebug() << mKeySettingsFile;
    saveSettings();
}

void XKeySettings::loadSettings()
{
    QSettings settings(mKeySettingsFile, QSettings::IniFormat);

}

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
