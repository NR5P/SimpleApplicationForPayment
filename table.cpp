#include "table.h"

Table::Table(Ui::MainWindow *ui)
{
    this->ui = ui;
    ui->lineItemsTable->resizeColumnsToContents();
    //ui->lineItemsTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

Table::~Table()
{
}

