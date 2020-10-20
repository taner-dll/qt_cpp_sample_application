#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "dbmanager.h"

#include <QDebug>
#include <QMessageBox>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    DBManager *dbm = new DBManager();
    dbm->openConnection("edro_db", "QMYSQL");
    dbm->connectMySQL();

    QString query = "SELECT fb.id, fb.topic, u.email FROM edro_db.feed_back fb "
                    "INNER JOIN edro_db.user u  ON u.id = fb.id";
    dbm->generateDynamicTableView(query, ui->tableView);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    dbm->closeConnection();

}

MainWindow::~MainWindow()
{
    delete ui;

}



void MainWindow::on_pushButton_2_clicked()
{





}

void MainWindow::on_pushButton_clicked()
{

    QMessageBox::critical(this, tr("Delete"),tr("SDFSDF"));

    int selected_row = ui->tableView->currentIndex().row();
    ui->tableView->hideRow(selected_row);

}
