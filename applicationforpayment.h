#include <QDate>
#include <QString>

#ifndef APPLICATIONFORPAYMENT_H
#define APPLICATIONFORPAYMENT_H


class ApplicationForPayment
{
public:
    ApplicationForPayment(int, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString);
    QString getFullAddress();

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

