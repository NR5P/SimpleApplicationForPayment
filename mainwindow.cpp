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

    projects.append("first project");
    projects.append("second project");
    projects.append("third project");
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
