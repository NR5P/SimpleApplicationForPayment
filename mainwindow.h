#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "database.h"
#include "table.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionNew_triggered();


    void on_buttonAddToForm_clicked();

    void on_buttonInsertIntoTableHere_clicked();

    void on_buttonDelete_clicked();

    void on_buttonBackProjectScreen_clicked();


    void on_buttonApplicationForPayment_clicked();
    void on_buttonNewProject_clicked();

private:
    Ui::MainWindow *ui;
    Table *table;
    Database *database;
    QString currentFile = "";
    const QString states[100] = {"state", "Alabama","Alaska","American Samoa","Arizona","Arkansas","California","Colorado","Connecticut","Delaware","District of Columbia","Federated States of Micronesia","Florida","Georgia","Guam","Hawaii","Idaho","Illinois","Indiana","Iowa","Kansas","Kentucky","Louisiana","Maine","Marshall Islands","Maryland","Massachusetts","Michigan","Minnesota","Mississippi","Missouri","Montana","Nebraska","Nevada","New Hampshire","New Jersey","New Mexico","New York","North Carolina","North Dakota","Northern Mariana Islands","Ohio","Oklahoma","Oregon","Palau","Pennsylvania","Puerto Rico","Rhode Island","South Carolina","South Dakota","Tennessee","Texas","Utah","Vermont","Virgin Island","Virginia","Washington","West Virginia","Wisconsin","Wyoming"};
    QList<QString> projects;
};
#endif // MAINWINDOW_H
