#include "project.h"

#include <QString>

Project::Project(int id, QString name, QString address, QString lastApplicationDate)
    : name(name), address(address)
{
    this->lastApplicationDate = QDate::fromString(lastApplicationDate, "dd/MM/yyyy");
}

