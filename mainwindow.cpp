#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSql>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //QWidget::showFullScreen();

    //initialize states dropdown
    for (int i = 0; i < 60; i++)
    {
        ui->inputCustomerState->insertItem(i, states[i]);
        ui->inputContractorState->insertItem(i, states[i]);
    }

    ui->lineItemsTable->resizeColumnsToContents();
    ui->stackedWidget->setCurrentIndex(1);

    database = new Database();

    QList<Project> projectModels = database->getProjectsFromDb();
    for (Project proj : projectModels)
    {
        projects.append(proj.getProjectDescription());
    }
    ui->projectList->setModel(new QStringListModel(projects));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete database;
}


void MainWindow::on_actionNew_triggered()
{

}


void MainWindow::on_buttonAddToForm_clicked()
{
    ui->lineItemsTable->insertRow(ui->lineItemsTable->rowCount());
}

void MainWindow::on_buttonInsertIntoTableHere_clicked()
{
    int rowSelected = ui->lineItemsTable->currentIndex().row();
    ui->lineItemsTable->insertRow(rowSelected);
}

void MainWindow::on_buttonDelete_clicked()
{
    int rowSelected = ui->lineItemsTable->currentIndex().row();
    ui->lineItemsTable->removeRow(rowSelected);
}

void MainWindow::on_buttonBackProjectScreen_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_buttonApplicationForPayment_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_buttonNewProject_clicked()
{
    newProject = true;
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_buttonSaveApplication_clicked()
{
    // get information from the application and create applicationforpayment
    QString projectCode = ui->projectCode->text();
    QString applicationNumber = ui->applicationNumber->text();
    QString applicationDate = ui->applicationDate->text();
    QString contractDate = ui->contractDate->text();
    QString periodFrom = ui->periodFrom->text();
    QString periodTo = ui->periodTo->text();
    QString customerName = ui->inputCustomerName->text();
    QString customerAddress = ui->inputCustomerAddress->text();
    QString customerCity = ui->inputCustomerCity->text();
    QString customerState = ui->inputCustomerState->currentText();
    QString customerZip = ui->inputCustomerZip->text();
    QString contractorName = ui->inputContractorName->text();
    QString contractorAddress = ui->inputContractorAddress->text();
    QString contractorCity = ui->inputContractorCity->text();
    QString contractorState = ui->inputContractorState->currentText();
    QString contractorZip = ui->inputContractorZip->text();
    ApplicationForPayment applicationForPayment = ApplicationForPayment(currentProjectId, projectCode, applicationNumber, applicationDate,contractDate, periodFrom, periodTo,
                                                                        customerName, customerAddress, customerCity, customerState, customerZip,
                                                                        contractorName, contractorAddress, contractorCity, contractorState, contractorZip);
    database->addApplicationForPayment(applicationForPayment, newProject, currentProjectId);
    ui->stackedWidget->setCurrentIndex(1);

    // return to the main project screen
}
