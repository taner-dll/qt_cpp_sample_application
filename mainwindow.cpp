#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dbmanager.h"

#include <QDebug>

#include <QSqlQueryModel>
#include <QSortFilterProxyModel>
#include <QSqlQuery>



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


void MainWindow::on_pushButton_clicked()
{

    DBManager *dbm = new DBManager();
    dbm->openConnection("edro_db", "QMYSQL");
    dbm->connectMySQL();


    dbm->testQuery("user");



    dbm->closeConnection();
    //qDebug() << dbm->isOpen();


}
