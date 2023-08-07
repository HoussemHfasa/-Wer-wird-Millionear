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
#include "Frage.h"
#include "GameSession.h"

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
    Player spieler("Houssam");

    // Überprüfe, ob der Spieler erfolgreich erstellt wurde
    std::cout << "Spielername: " << spieler.getNickname() << std::endl;
    std::cout << "Highscore: " << spieler.getBestScore() << std::endl;
    std::cout << "Aktueller Score: " << spieler.getCurrentScore() << std::endl;

    // Aktualisiere den Score des Spielers
    spieler.updateScore(1000);
    std::cout << "Aktualisierter Highscore: " << spieler.getBestScore() << std::endl;
    std::cout << "Aktualisierter Score: " << spieler.getCurrentScore() << std::endl;

    // Verwende eine Lifeline


}

void testFrageClass() {
    srand(time(0)); // Initialisiere den Zufallsgenerator

    string kategorie = "Geschichte";
    string schwierigkeit = "einfach";

    Frage frage1 = Frage::erstelleZufaelligeFrage(kategorie, schwierigkeit);


    // Teste die getFrage-Methode
    std::string frageText = frage1.getFrage();
    std::cout << "Frage: " << frageText << std::endl;

    // Teste die getAntworten-Methode
    std::vector<std::string> antworten = frage1.getAntworten();
    std::cout << "Antworten:" << std::endl;
    for (const std::string& antwort : antworten) {
        std::cout << antwort << std::endl;
    }

    // Teste die getRichtigeAntwort-Methode
    char richtigeAntwort = frage1.getRichtigeAntwort();
    std::cout << "Richtige Antwort: " << richtigeAntwort << std::endl;

    // Teste die getKategorie-Methode
    std::string frageKategorie = frage1.getKategorie();
    std::cout << "Frage Kategorie: " << frageKategorie << std::endl;

    // Teste die istAntwortKorrekt-Methode
    char benutzerAntwort = 'A'; // Annahme: Der Benutzer wählt Antwort A
    bool istKorrekt = frage1.istAntwortKorrekt(benutzerAntwort);
    std::cout << "Ist Antwort korrekt? " << (istKorrekt ? "Ja" : "Nein") << std::endl;
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
    query.prepare("SELECT nickname, highscore FROM benutzer");

    if (query.exec()) {
         while (query.next()) {
            qDebug() << query.value(0).toString() << ":"
                     << query.value(1).toInt() << ","
                     << query.value(2).toInt() ;
        }
    } else {
        qDebug() << "Error: " << query.lastError();
    }
    cout <<query.value(0).toInt()<<endl;
    testPlayerClass();
    return a.exec();
}
