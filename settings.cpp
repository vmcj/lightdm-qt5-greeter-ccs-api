#include <QDebug>
#include <QDir>
#include "settings.h"

#define LOGFILE_PATH_KEY "logfile-path"

const QString Cache::GREETER_DATA_DIR_PATH = "/var/lib/lightdm/lightdm-qt5-greeter";

void Cache::prepare()
{
    QDir dir(GREETER_DATA_DIR_PATH);
    if (!dir.exists()) {
        if (!dir.mkpath(GREETER_DATA_DIR_PATH)) {
            qWarning() << "Unable to create dir" << GREETER_DATA_DIR_PATH;
        }
    }
}
