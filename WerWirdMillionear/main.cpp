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
#include <QMediaPlayer>
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
    cout << "Spielername: " << spieler.getNickname() << endl;
    cout << "Highscore: " << spieler.getBestScore() << endl;
    cout << "Aktueller Score: " << spieler.getCurrentScore() <<endl;

    // Aktualisiere den Score des Spielers
    spieler.updateScore(1000);
    cout << "Aktualisierter Highscore: " << spieler.getBestScore() << endl;
    cout << "Aktualisierter Score: " << spieler.getCurrentScore() << endl;

    // Verwende eine Lifeline


}

void testFrageClass() {
    srand(time(0)); // Initialisiere den Zufallsgenerator

    string kategorie = "Geschichte";
    string schwierigkeit = "einfach";

    Frage frage1 = Frage::erstelleZufaelligeFrage(kategorie, schwierigkeit);


    // Teste die getFrage-Methode
    string frageText = frage1.getFrage();
    cout << "Frage: " << frageText << endl;

    // Teste die getAntworten-Methode
    vector<string> antworten = frage1.getAntworten();
    cout << "Antworten:" << endl;
    for (const string& antwort : antworten) {
        cout << antwort <<endl;
    }

    // Teste die getRichtigeAntwort-Methode
    char richtigeAntwort = frage1.getRichtigeAntwort();
    cout << "Richtige Antwort: " << richtigeAntwort <<endl;

    // Teste die getKategorie-Methode
    string frageKategorie = frage1.getKategorie();
    cout << "Frage Kategorie: " << frageKategorie << endl;

    // Teste die istAntwortKorrekt-Methode
    char benutzerAntwort = 'A'; // Annahme: Der Benutzer wählt Antwort A
    bool istKorrekt = frage1.istAntwortKorrekt(benutzerAntwort);
    cout << "Ist Antwort korrekt? " << (istKorrekt ? "Ja" : "Nein") << endl;
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



    return a.exec();
}
