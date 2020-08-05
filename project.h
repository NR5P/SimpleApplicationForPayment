#ifndef PROJECT_H
#define PROJECT_H

#include <QDate>
#include <QString>



class Project
{
public:
    Project(int id, QString, QString, QString);
    QString getProjectDescription();

    QString name;
    QDate lastApplicationDate;
    QString address;
};

#endif // PROJECT_H
