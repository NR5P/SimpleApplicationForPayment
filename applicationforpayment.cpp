#include "applicationforpayment.h"

ApplicationForPayment::ApplicationForPayment(int id, int projectId, QString projectCode, QString applicationNumber, QString applicationDate,
                                             QString contractDate, QString periodFrom, QString periodTo, QString customerName, QString customerAddress,
                                             QString customerCity, QString customerState, QString customerZip, QString contractorName,
                                             QString contractorAddress, QString contractorCity, QString contractorState, QString contractorZip)
    : id(id), projectId(projectId), projectCode(projectCode), applicationNumber(applicationNumber), customerName(customerName), customerAddress(customerAddress),customerCity(customerCity),
      customerState(customerState), customerZip(customerZip), contractorName(contractorName), contractorAddress(contractorAddress), contractorCity(contractorCity),
      contractorState(contractorState), contractorZip(contractorZip)
{
    this->applicationDate = QDate::fromString(applicationDate, "dd/MM/yyyy");
    this->contractDate = QDate::fromString(contractDate, "dd/MM/yyyy");
    this->periodFrom = QDate::fromString(periodFrom, "dd/MM/yyyy");
    this->periodTo = QDate::fromString(periodTo, "dd/MM/yyyy");
}
