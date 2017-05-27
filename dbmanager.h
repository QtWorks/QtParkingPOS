#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

const QString ventas = "CREATE TABLE IF NOT EXISTS VENTAS("
                       "FOLIO VARCHAR(18) PRIMARY KEY NOT NULL,"
                       "HORA VARCHAR(5) NOT NULL,"
                       "FECHA DATE NOT NULL,"
                       "BOLETERA CHAR(1) NOT NULL,"
                       "TIPO INTEGER NOT NULL,"
                       "COSTO REAL NOT NULL);";
const QString costos = "CREATE TABLE IF NOT EXISTS COSTOS("
                       "TIPO INTEGER PRIMARY KEY,"
                       "COSTO REAL NOT NULL,"
                       "TOLERANCIA INTEGER);";
const QString login = "CREATE TABLE IF NOT EXISTS LOGIN("
                      "USERNAME VARCHAR(8) PRIMARY KEY,"
                      "PASSWORD VARCHAR(8) NOT NULL);";
const QString tickets = "CREATE TABLE IF NOT EXISTS TICKETS("
                        "FOLIO VARCHAR(8) PRIMARY KEY,"
                        "HORA VARCHAR(5) NOT NULL,"
                        "FECHA DATE NOT NULL);";
const QString DRIVER = "QSQLITE";

typedef struct
{
    QString username;
    QString password;
} QUserData;

class DBManager
{
public:
    DBManager(const QString& path);
    ~DBManager();
    bool isOpen() const;
    bool open();
    void close();
    bool executeQuery(const QString& s_query);
    bool createTable(const QString& name, QVector<QString>& fields);
    bool addUser(const QString& name, const QString& password);
    bool deleteUser(const QString& name);
    bool userExists(const QString& name) const;
    bool addTicketToDatabase(const QString& serial_number);
    bool initAllTables();
    QUserData getUserData(const QString& username);
    QSqlError lastError() const;
private:
    QSqlDatabase m_db;
};

#endif // DBMANAGER_H
