#include "mainwindow.h"
#include "table.h"
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
    table = new Table(ui);
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
    delete table;
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
    // if new project create a new project in db

    // get information from the application and create applicationforpayment

    // call insert function from database to insert new one

    // return to the main project screen
}
