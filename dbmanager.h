#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QString>
#include <QSqlDatabase>

#include <QTableView>


class DBManager
{
public:
    DBManager();
    ~DBManager();
    QSqlDatabase db;
    bool isOpen();
    void openConnection(const QString &path, const QString &dbType);
    void closeConnection();
    void connectMySQL();
    void testQuery(const QString &table_name);
    void generateDynamicTableView(const QString &sql_query_text, QTableView *tv);


private:

};

#endif // DBMANAGER_H
