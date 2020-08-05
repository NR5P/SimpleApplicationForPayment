#ifndef DATABASE_H
#define DATABASE_H

#include "project.h"
#include "applicationforpayment.h"

#include <QSqlDatabase>
#include <QString>



class Database
{
public:
    Database();
    QList<Project> getProjectsFromDb();
    QList<ApplicationForPayment> getApplicationsForPayment(int projectId);
private:
    const QString dbName;
    QSqlDatabase mydb;
};

#endif // DATABASE_H
