#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "dbmanager.h"

#include <QDebug>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;

}



void MainWindow::on_pushButton_2_clicked()
{

    DBManager *dbm = new DBManager();

    dbm->openConnection("edro_db", "QMYSQL");
    dbm->connectMySQL();

    QString query = "select * from user where id between 10 and 13";
    dbm->generateDynamicTableView(query, ui->tableView1);


    dbm->closeConnection();



}
