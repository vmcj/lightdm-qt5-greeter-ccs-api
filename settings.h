#ifndef SETTINGS_H
#define SETTINGS_H

#include <QSettings>

class Cache : public QSettings
{
public:
    static const QString GREETER_DATA_DIR_PATH;
    static void prepare();

    Cache() : QSettings(GREETER_DATA_DIR_PATH + "/state", QSettings::NativeFormat) {}
    QString getLastUser() { return value("last-user").toString(); }
    void setLastUser(QString userId) { setValue("last-user", userId); }
    QString getLastSession(QString userId) { return value(userId + "/last-session").toString(); }
    void setLastSession(QString userId, QString session) { setValue(userId + "/last-session", session); }
};

#define CONFIG_FILE "/etc/lightdm/lightdm-qt5-greeter.conf"
#define GREETER_ICON_THEME "greeter-icon-theme"
#define BACKGROUND_IMAGE_KEY "greeter-background-image"
#define LOGINFORM_OFFSETX_KEY "loginform-offset-x"
#define LOGINFORM_OFFSETY_KEY "loginform-offset-y"
#define LOGINFORM_SHOW_INPUT_CHAIN "loginform-show-input-chain"

class Settings : public QSettings
{
public:
    Settings() : QSettings(QString(CONFIG_FILE), QSettings::NativeFormat) {}
    QString iconThemeName() { return value(GREETER_ICON_THEME).toString(); }
    QString backgrundImagePath() { return value(BACKGROUND_IMAGE_KEY).toString(); }
    QString offsetX() { return value(LOGINFORM_OFFSETX_KEY).toString(); }
    QString offsetY() { return value(LOGINFORM_OFFSETY_KEY).toString(); }
    QStringList loginformShowInputChain() { return value(LOGINFORM_SHOW_INPUT_CHAIN).toStringList(); }
};

#endif // SETTINGS_H
