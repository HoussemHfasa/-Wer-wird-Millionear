#include "mainwindow.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>

#include <QApplication>
#include <QDir>
#include <QFile>
#include <QProcessEnvironment>

#include <iostream>
using namespace  std;

#include <iostream>
#include "player.h"


void loadEnvVars() {

    QFile envFile(".env");
    if(!envFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << ".env file not found";
        return;
    }

    QTextStream in(&envFile);
    while(!in.atEnd()) {
        QString line = in.readLine();
        auto parts = line.split("=");
        if(parts.size() == 2) {
            qputenv(parts[0].toUtf8(), parts[1].toUtf8());
        }
    }
    envFile.close();
}

void testPlayerClass() {
    // Erstelle einen Spieler mit dem Namen "Max Mustermann"
    Player spieler("Max Mustermann");

    // Überprüfe, ob der Spieler erfolgreich erstellt wurde
    std::cout << "Spielername: " << spieler.getNickname() << std::endl;
    std::cout << "Highscore: " << spieler.getBestScore() << std::endl;
    std::cout << "Aktueller Score: " << spieler.getCurrentScore() << std::endl;
    std::cout << "Lifelines: " << spieler.getLifelines() << std::endl;

    // Aktualisiere den Score des Spielers
    spieler.updateScore(1000);
    std::cout << "Aktualisierter Highscore: " << spieler.getBestScore() << std::endl;
    std::cout << "Aktualisierter Score: " << spieler.getCurrentScore() << std::endl;

    // Verwende eine Lifeline
    spieler.useLifeline();
    std::cout << "Verbleibende Lifelines: " << spieler.getLifelines() << std::endl;
}



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    //creating database connection
    qDebug() << QDir::currentPath();
    loadEnvVars();
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    QProcessEnvironment env = QProcessEnvironment::systemEnvironment();
    db.setDatabaseName("Driver={MySQL ODBC 8.1 Unicode Driver};SERVER="+ env.value("DB_HOST")+";DATABASE="+env.value("DB_NAME")+";USER=" + env.value("DB_USER") + ";PASSWORD=" + env.value("DB_PASS") + ";");
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

     testPlayerClass();

     return a.exec();

}
