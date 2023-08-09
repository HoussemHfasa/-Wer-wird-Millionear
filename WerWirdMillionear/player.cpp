#include "Player.h"
#include <QSqlQuery>
#include <QtSql/QSqlError>
#include <iostream>
using namespace std;


// Konstruktor, initialisiert den Spieler mit dem gegebenen Nickname

Player::Player(const std::string& nickname1) {
    QSqlQuery query;
    nickname=nickname1;

    // Versuche, den Spieler mit dem gegebenen Nickname aus der Datenbank abzurufen

    query.prepare("SELECT * FROM benutzer WHERE nickname = :nickname");
    query.bindValue(":nickname", QString::fromStdString(nickname));
    query.exec();

    if (query.next()) {
        // Der Spieler mit dem gegebenen Nickname wurde gefunden
        bestScore = query.value(1).toInt();
        currentScore = query.value(2).toInt();
    } else {
        // Der Spieler wurde nicht gefunden, fügen Sie einen neuen Spieler hinzu
        query.prepare("INSERT INTO benutzer (nickname, Highscore, currentScore) "
                      "VALUES (:nickname, :bestScore, :currentScore)");
        query.bindValue(":nickname", QString::fromStdString(nickname));
        query.bindValue(":bestScore", 0);
        query.bindValue(":currentScore", 0);
        query.exec();
    }
}

// Gibt den Nickname des Spielers zurück

string Player::getNickname() const {
    QSqlQuery query;
    query.prepare("SELECT nickname FROM benutzer WHERE nickname = :nickname");
    query.bindValue(":nickname", QString::fromStdString(nickname));
    if (query.exec() && query.next()) {
        return query.value(0).toString().toStdString();
    }
    return ""; // Leerer String, falls keine Daten gefunden wurden oder ein Fehler auftrat
}

// Gibt den besten Punktestand des Spielers zurück

int Player::getBestScore() const {
    QSqlQuery query;
    query.prepare("SELECT Highscore FROM benutzer WHERE nickname = :nickname");
    query.bindValue(":nickname", QString::fromStdString(nickname));
    if (query.exec() && query.next()) {
        return query.value(0).toInt(); // Hier wird der Wert des Highscore-Feldes in der ersten Zeile zurückgegeben
    }
    // Wenn die Abfrage fehlschlägt oder kein Ergebnis zurückgibt, geben Sie einen Standardwert zurück
    return 0; // Standardwert für den Highscore, wenn es keine Daten gibt oder ein Fehler auftritt
}

// Gibt den aktuellen Punktestand des Spielers zurück

int Player::getCurrentScore() const {
    QSqlQuery query;
    query.prepare("SELECT currentScore FROM benutzer WHERE nickname = :nickname");
    query.bindValue(":nickname", QString::fromStdString(nickname));
    if (query.exec() && query.next()) {
        return query.value(0).toInt();
    }
    return 0;
}

// Aktualisiert den Spielerpunktestand und den besten Punktestand

void Player::updateScore(int newScore) {
    currentScore = newScore;
    // Aktualisiere den besten Punktestand, falls der neue Punktestand höher ist
    if (newScore > bestScore) {
        bestScore = newScore;
    }
    // Setze den aktuellen Punktestand auf 0, wenn der Spieler den Hauptpreis von 1.000.000 erreicht hat
    if(newScore==1000000)
    {
        currentScore=0;
    }

    // Aktualisiere den Punktestand in der Datenbank

    QSqlQuery query;
    query.prepare("UPDATE benutzer SET Highscore = :bestScore WHERE nickname = :nickname");
    query.bindValue(":bestScore", bestScore); // Hier wird der Platzhalter :bestScore mit dem Wert von bestScore ersetzt
    query.bindValue(":newScore", newScore);
    query.bindValue(":nickname",  QString::fromStdString(nickname)); // Hier wird der Platzhalter :currentScore mit dem Wert von currentScore ersetzt
    query.exec();
    query.prepare("UPDATE benutzer SET currentScore = :newScore WHERE nickname = :nickname");
    query.bindValue(":newScore", currentScore);
    query.bindValue(":nickname",  QString::fromStdString(nickname)); // Hier wird der Platzhalter :currentScore mit dem Wert von currentScore ersetzt
    query.exec();
}

// Ruft alle Spieler und ihre besten Punktestände aus der Datenbank ab

void Player::getAllPlayers()
{
    QSqlQuery query;
    query.prepare("SELECT NICKNAME,HIGHSCORE FROM BENUTZER;");
    if (query.exec()) {
        while (query.next()) {
            qDebug() << query.value(0).toString() << ":"
                     << query.value(1).toInt();
        }
    } else {
        qDebug() << "Error: " << query.lastError();
    }
}


