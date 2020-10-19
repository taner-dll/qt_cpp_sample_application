/**
* @author Taner Deliloglu
* Contact: tnrdll@gmail.com
*/

#include "dbmanager.h"

#include <QtSql>
#include <QSqlQuery>



//constructor
DBManager::DBManager()
{
    QSqlDatabase db;
}

void DBManager::openConnection(const QString &path, const QString &dbType){
    this->db = QSqlDatabase::addDatabase(dbType); //QMYSQL, QSQLITE...
    this->db.setDatabaseName(path); //db name or path
}


void DBManager::connectMySQL()
{
    this->db.setHostName("127.0.0.1");
    this->db.setUserName("root");
    this->db.setPassword("63845489");

    if(!this->db.open())
        qDebug() << "Database: MySQL connection failed!";
    else
        qDebug() << "Database: MySQL connection has been successfully opened";
}



void DBManager::closeConnection(){
    this->db.close();
    qDebug() << "Database: connection has been closed";
}



void DBManager::testQuery(const QString &table_name){
    QSqlQuery query;
    query.exec("SELECT id FROM "+table_name);
    while (query.next()) {
        int id = query.value(0).toInt();
        //QString email = query.value(1).toString();
        qDebug() << id;
    }
}


bool DBManager::isOpen(){
    return this->db.isOpen();
}

