#include "t_toon.h"
#include <QFileInfo>

t_toon::t_toon()
{

}

bool t_toon::setLogFile(const std::string &filePath)
{
    QFileInfo logFile(QString::fromStdString(filePath));
    if (logFile.exists() && logFile.isFile())
    {
        //Write settings to config file
        this->logFile = filePath;
        return true;
    }
    else
    {
        return false;
    }
}

std::string t_toon::getLogFile(void)
{
    return this->logFile;
}
