#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "dbmanager.h"

#include <QDebug>
#include <QMessageBox>
#include <QThread>



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
    QMessageBox::critical(this, tr("Delete"),tr("SDFSDF"));

    int selected_row = ui->tableView->currentIndex().row();
    ui->tableView->hideRow(selected_row);
}



void MainWindow::on_fetch_feedback_button_clicked()
{
    DBManager *dbm = new DBManager();
    dbm->openConnection("edro_db", "QMYSQL");
    dbm->connectMySQL();

    QString query = "SELECT fb.id, fb.topic, u.email FROM edro_db.feed_back fb "
                    "INNER JOIN edro_db.user u  ON u.id = fb.id";
    dbm->generateDynamicTableView(query, ui->tableView);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    dbm->closeConnection();


    //QThread::sleep(2);




}





void MainWindow::on_pushButton_2_clicked()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Başarılı");
    msgBox.setText("Geri bildirimler başarıyla getirildi.");
    msgBox.setButtonText(msgBox.Ok, "Tamam");
    msgBox.setDetailedText("detay...");
    msgBox.exec();
}

void MainWindow::on_pushButton_3_clicked()
{

    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setText("Dosya değiştirilmiş.");
    msgBox.setInformativeText("Değişiklikleri kaydetmek istiyor musunuz?");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();


    switch (ret) {
      case QMessageBox::Save:
          qDebug() << "Kaydedildi";
          break;
      case QMessageBox::Discard:
          qDebug() << "Kaydedilmedi";
          break;
      case QMessageBox::Cancel:
          qDebug() << "İşlem İptal Edildi";
          break;
      default:
          break;
    }
}
