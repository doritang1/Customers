#ifndef INITDB
#define INITDB
#include <QtSql>
#include <QMessageBox>
void createTables()
{
    QSqlQuery query;

     if(query.exec(QLatin1String("create table customerInfo"
                                 " (customerId varchar,"
                                 " enterpriseName varchar,"
                                 " ceoName varchar,"
                                 " etc varchar)")))
     {
         QMessageBox::information(0, "success to create table", "테이블 만들기 성공");
     }
}

void addCustomer(const QString &id, const QString &title, const QString &ceo, const QString &etc)
{
    QSqlQuery query;
    query.prepare("insert into customerInfo(customerId, enterpriseName, ceoName, etc) values(?, ?, ?, ?)");
    query.addBindValue(id);
    query.addBindValue(title);
    query.addBindValue(ceo);
    query.addBindValue(etc);
    query.exec();
}

void initDb(const QString &dbFileDir)
{
    QSqlDatabase customers = QSqlDatabase::addDatabase("QSQLITE");
    customers.setDatabaseName(dbFileDir + "customer.sqlite");
    if(!customers.open()){
        QMessageBox::warning(0, "fail to open the database", "Database열기 실패");
        return;
    }
}
#endif // INITDB

