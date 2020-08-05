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
