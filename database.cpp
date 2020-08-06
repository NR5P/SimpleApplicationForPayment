#include "database.h"
#include "project.h"

#include <QFile>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDir>
#include <QVariant>
#include <QDate>
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
    QSqlQuery query("SELECT projectId, projectCode, applicationNumber, applicationDate, contractDate, periodFrom"
                    "periodTo, customerName, customerAddress, customerCity, customerState, customerZip, contractorName,"
                    "contractorAddress, contractorCity, contractorState, contractorZip"
                    "FROM applicationForPayments WITH projectId = " + QString::number(projectId));
    while(query.next())
    {
        ApplicationForPayment applicationForPayment = ApplicationForPayment(query.value(0).toInt(), query.value(1).toString(), query.value(2).toString(), query.value(3).toString(),
                                                                            query.value(4).toString(), query.value(5).toString(), query.value(6).toString(), query.value(7).toString(),
                                                                            query.value(8).toString(), query.value(9).toString(), query.value(10).toString(), query.value(11).toString(),
                                                                            query.value(12).toString(), query.value(13).toString(), query.value(14).toString(), query.value(15).toString(),
                                                                            query.value(16).toString());
        applicationForPayments.append(applicationForPayment);
    }
    return applicationForPayments;
}

void Database::addApplicationForPayment(ApplicationForPayment applicationForPayment, bool newProject, int projectId)
{
    QString projectCode = applicationForPayment.projectCode;
    QString applicationNumber = applicationForPayment.applicationNumber;
    QString applicationDate = applicationForPayment.applicationDate.toString("MM/dd/yyyy");
    QString contractDate = applicationForPayment.contractDate.toString("MM/dd/yyyy");
    QString periodFrom = applicationForPayment.periodFrom.toString("MM/dd/yyyy");
    QString periodTo = applicationForPayment.periodTo.toString("dd/MM/yyyy");
    QString customerName = applicationForPayment.customerName;
    QString customerAddress = applicationForPayment.customerAddress;
    QString customerCity = applicationForPayment.customerCity;
    QString customerState = applicationForPayment.customerState;
    QString customerZip = applicationForPayment.customerZip;
    QString contractorName = applicationForPayment.contractorName;
    QString contractorAddress = applicationForPayment.contractorAddress;
    QString contractorCity = applicationForPayment.contractorCity;
    QString contractorState = applicationForPayment.contractorState;
    QString contractorZip = applicationForPayment.contractorZip;
    QString lastProjectDate = applicationForPayment.applicationDate.toString("dd/MM/yyyy");
    if (newProject)
    {
        QSqlQuery query;
        query.prepare("INSERT INTO projects (name, address, lastProjectDate) VALUES(:customerName, :customerAddress, :lastProjectDate);");
        query.bindValue(":customerName",customerName);
        query.bindValue(":customerAddrss",customerAddress);
        query.bindValue(":lastProjectDate",lastProjectDate);
        query.exec();
        QString lastInsertId = query.lastInsertId().toString();
        QSqlQuery query2;
        query2.prepare("INSERT INTO applicationForPayments (projectCode, applicationNumber, applicationDate, contractDate,"
                 "periodFrom, periodTo, customerName, customerAddress, customerCity, customerState, customerZip,"
                 "contractorName, contractorAddress, contractorCity, contractorState, contractorZip, projectId"
                 ") VALUES(:projectCode, :applicationNumber, :applicationDate, :contractDate, :perodFrom, :periodTo,"
                       ":customerName, :customerAddress, :customerCity, :customerState, :customerZip,"
                       ":contractorName, :contractorAddress, :contractorCity, :contractorState, :contractorZip, :projectId);");
        query2.bindValue(":projectCode", projectCode);
        query2.bindValue(":applicationNumber", applicationNumber);
        query2.bindValue(":applicationDate", applicationDate);
        query2.bindValue(":contractDate", contractDate);
        query2.bindValue(":periodFrom", periodFrom);
        query2.bindValue(":periodTo", periodTo);
        query2.bindValue(":customerName", customerName);
        query2.bindValue(":customerAddress", customerAddress);
        query2.bindValue(":customerCity", customerCity);
        query2.bindValue(":customerState", customerState);
        query2.bindValue(":customerZip", customerZip);
        query2.bindValue(":contractorName", contractorName);
        query2.bindValue(":contractorAddress", contractorAddress);
        query2.bindValue(":contractorCity", contractorCity);
        query2.bindValue(":contractorState", contractorState);
        query2.bindValue(":contractorZip", contractorZip);
        query2.bindValue(":projectId", lastInsertId);
        query2.exec();

    } else {
        QSqlQuery query2;
        query2.prepare("INSERT INTO applicationForPayments (projectCode, applicationNumber, applicationDate, contractDate,"
                 "periodFrom, periodTo, customerName, customerAddress, customerCity, customerState, customerZip,"
                 "contractorName, contractorAddress, contractorCity, contractorState, contractorZip, projectId"
                 ") VALUES(:projectCode, :applicationNumber, :applicationDate, :contractDate, :perodFrom, :periodTo,"
                       ":customerName, :customerAddress, :customerCity, :customerState, :customerZip,"
                       ":contractorName, :contractorAddress, :contractorCity, :contractorState, :contractorZip, :projectId)");
        query2.bindValue(":projectCode", projectCode);
        query2.bindValue(":applicationNumber", applicationNumber);
        query2.bindValue(":applicationDate", applicationDate);
        query2.bindValue(":contractDate", contractDate);
        query2.bindValue(":periodFrom", periodFrom);
        query2.bindValue(":periodTo", periodTo);
        query2.bindValue(":customerName", customerName);
        query2.bindValue(":customerAddress", customerAddress);
        query2.bindValue(":customerCity", customerCity);
        query2.bindValue(":customerState", customerState);
        query2.bindValue(":customerZip", customerZip);
        query2.bindValue(":contractorName", contractorName);
        query2.bindValue(":contractorAddress", contractorAddress);
        query2.bindValue(":contractorCity", contractorCity);
        query2.bindValue(":contractorState", contractorState);
        query2.bindValue(":contractorZip", contractorZip);
        query2.bindValue(":projectId", projectId);
        query2.exec();

    }
}


