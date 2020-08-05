#include "project.h"

#include <QString>

Project::Project(int id, QString name, QString address, QString lastApplicationDate)
    : name(name), address(address)
{
    this->lastApplicationDate = QDate::fromString(lastApplicationDate, "MM/dd/yyyy");
}

QString Project::getProjectDescription()
{
    return name + " " + address + " " + lastApplicationDate.toString("MM/dd/yyyy");
}


