#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QString>
#include <QSqlDatabase>



class DBManager
{
public:
    DBManager();
    ~DBManager();
    void openConnection(const QString &path, const QString &dbType);
    void closeConnection();
    void connectMySQL();

    void testQuery(const QString &table_name);
    bool isOpen();
    QSqlDatabase db;


private:

};

#endif // DBMANAGER_H
