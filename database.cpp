#include "database.h"
#include "project.h"

#include <QFile>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDir>
#include <QVariant>

Database::Database()
{
        QDir path;
        QString dbPath = path.currentPath() + "mydb.db";
        mydb = QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName(dbPath);
        mydb.open();
        QSqlQuery query0("PRAGMA foreign_keys = ON");
        QSqlQuery query1("CREATE TABLE projects (id INTEGER PRIMARY KEY, name TEXT, address TEXT, lastProjectDate TEXT)");
        QSqlQuery query2("CREATE TABLE applicationForPayments (id INTEGER PRIMARY KEY, projectCode TEXT, applicationNumber TEXT, applicationDate TEXT,"
                         "contractDate TEXT, periodFrom TEXT, periodTo TEXT, customerName TEXT customerAddress TEXT, customerCity TEXT, customerState TEXT,"
                         "customerZip TEXT, contractorName TEXT, contractorAddress TEXT, contractorCity TEXT, contractorState TEXT, contractorZip TEXT,"
                         "projectId INTEGER, FOREIGN KEY (projectId) REFERENCES projects(id))");
        QSqlQuery query3("CREATE TABLE settings (id INTEGER PRIMARY KEY, darkMode INTEGER)");
}

QList<Project> Database::getProjectsFromDb()
{
    QList<Project> projects;
    QSqlQuery query("SELECT id, name, address, lastProjectDate FROM projects");
    while(query.next())
    {
        Project project = Project(query.value(0).toInt(), query.value(1).toString(), query.value(2).toString(), query.value(3).toString());
        projects.append(project);
    }
    return projects;
}

QList<ApplicationForPayment> Database::getApplicationsForPayment(int projectId)
{
    QList<ApplicationForPayment> applicationForPayments;
    QSqlQuery query("SELECT id, projectId, projectCode, applicationNumber, applicationDate, contractDate, periodFrom"
                    "periodTo, customerName, customerAddress, customerCity, customerState, customerZip, contractorName,"
                    "contractorAddress, contractorCity, contractorState, contractorZip"
                    "FROM applicationForPayments WITH projectId = " + QString::number(projectId));
    while(query.next())
    {
        ApplicationForPayment applicationForPayment = ApplicationForPayment(query.value(0).toInt(), query.value(1).toInt(), query.value(2).toString(), query.value(3).toString(),
                                                                            query.value(4).toString(), query.value(5).toString(), query.value(6).toString(), query.value(7).toString(),
                                                                            query.value(8).toString(), query.value(9).toString(), query.value(10).toString(), query.value(11).toString(),
                                                                            query.value(12).toString(), query.value(13).toString(), query.value(14).toString(), query.value(15).toString(),
                                                                            query.value(16).toString(), query.value(17).toString());
        applicationForPayments.append(applicationForPayment);
    }
    return applicationForPayments;
}


