#include <QDate>
#include <QString>

#ifndef APPLICATIONFORPAYMENT_H
#define APPLICATIONFORPAYMENT_H


class ApplicationForPayment
{
public:
    ApplicationForPayment(int, int, QString, QString, QDate, QDate, QDate, QDate, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString);

private:
    int id;
    int projectId;
    QString projectCode;
    QString applicationNumber;
    QDate applicationDate;
    QDate contractDate;
    QDate periodFrom;
    QDate periodTo;
    QString customerName;
    QString customerAddress;
    QString customerCity;
    QString customerState;
    QString customerZip;
    QString contractorName;
    QString contractorAddress;
    QString contractorCity;
    QString contractorState;
    QString contractorZip;
};

#endif // APPLICATIONFORPAYMENT_H

QSqlQuery query2("CREATE TABLE applicationForPayments (id INTEGER PRIMARY KEY, projectCode TEXT, applicationNumber TEXT, applicationDate TEXT,"
         "contractDate TEXT, periodFrom TEXT, periodTo TEXT, customerName TEXT customerAddress TEXT, customerCity TEXT, customerState TEXT,"
         "customerZip TEXT, contractorName TEXT, contractorAddress TEXT, contractorCity TEXT, contractorState TEXT, contractorZip TEXT,"
         "projectId INTEGER, FOREIGN KEY (projectId) REFERENCES projects(id))");
