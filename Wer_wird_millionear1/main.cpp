#include "mainwindow.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>

#include <QApplication>

#include <iostream>
using namespace  std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    //creating database connection
     QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
     db.setDatabaseName("Driver={MySQL ODBC 8.1 Unicode Driver};SERVER=localhost;DATABASE=werwirdmillionaer;USER=rama;PASSWORD=12345;");
     if(db.open())
     {
        cout << "Database connected" << endl;
     }
     else {
        cout << "Database connect failed" << endl;
        cout << db.lastError().text().toStdString() << endl;
     }

     QSqlQuery query;
     /*query.prepare("SELECT * FROM fragenkatalog_einfach");

    if (query.exec()) {
        while (query.next()) {
            qDebug() << query.value(0).toInt() << ":"
                     << query.value(1).toString() << ","
                     << query.value(6).toString() << ","
                     << query.value(5).toString();
        }
    } else {
        qDebug() << "Error: " << query.lastError();
    }*/
     query.prepare("SELECT * FROM fragenkatalog_einfach WHERE FrageID = 5");

     if (query.exec()) {
         if (query.next()) {
             qDebug() << query.value(0).toInt() << ":"
                      << query.value(1).toString() << ","
                      << query.value(6).toString() << ","
                      << query.value(5).toString();
         }
     } else {
         qDebug() << "Error: " << query.lastError();
     }
     cout <<query.value(0).toInt()<<endl;

    return a.exec();
}
