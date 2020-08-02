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
        ui->customerState->insertItem(i, states[i]);
        ui->contractorState->insertItem(i, states[i]);
    }
    table = new Table(ui);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete table;
}


void MainWindow::on_actionNew_triggered()
{
    currentFile.clear();

}


void MainWindow::on_btnAddToForm_clicked()
{
    ui->lineItemsTable->insertRow(ui->lineItemsTable->rowCount());
}

void MainWindow::on_btnInsertIntoTableHere_clicked()
{
    int rowSelected = ui->lineItemsTable->currentIndex().row();
    ui->lineItemsTable->insertRow(rowSelected);
}

void MainWindow::on_pushButton_clicked()
{
    int rowSelected = ui->lineItemsTable->currentIndex().row();
    ui->lineItemsTable->removeRow(rowSelected);
}
