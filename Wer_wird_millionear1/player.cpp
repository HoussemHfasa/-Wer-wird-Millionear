#include "Player.h"
#include <QSqlQuery>
using namespace std;
Player::Player(const string& nickname)
    : nickname(nickname), bestScore(0), currentScore(0), lifelines(3) {
    id = generateID();

    QSqlQuery query;
    query.prepare("INSERT INTO benutzer (id, nickname, Highscore, currentScore, lifelines) "
                  "VALUES (:id, :nickname, :bestScore, :currentScore, :lifelines)");
    query.bindValue(":id", id);
    query.bindValue(":nickname", QString::fromStdString(nickname));
    query.bindValue(":bestScore", bestScore);
    query.bindValue(":currentScore", currentScore);
    query.bindValue(":lifelines", lifelines);
    query.exec();
}


int Player::generateID() {
    QSqlQuery query("SELECT MAX(id) FROM benutzer");
    if (query.exec() && query.next()) {
        return query.value(0).toInt() + 1;
    }
    return 1; // Fallback-Wert, falls keine ID gefunden wurde oder ein Fehler aufgetreten ist
}

string Player::getNickname() const {
    QSqlQuery query;
    query.prepare("SELECT nickname FROM benutzer WHERE id = :id");
    query.bindValue(":id", id);
    if (query.exec() && query.next()) {
        return query.value(0).toString().toStdString();
    }
    return ""; // Leerer String, falls keine Daten gefunden wurden oder ein Fehler auftrat
}


int Player::getBestScore() const {
    QSqlQuery query;
    query.prepare("SELECT Highscore FROM benutzer WHERE id = :id");
    query.bindValue(":id", id);
    if (query.exec()) {
        if (query.next()) {
            return query.value(0).toInt(); // Hier wird der Wert des Highscore-Feldes in der ersten Zeile zurückgegeben
        }
    }
    // Wenn die Abfrage fehlschlägt oder kein Ergebnis zurückgibt, geben Sie einen Standardwert zurück
    return 0; // Standardwert für den Highscore, wenn es keine Daten gibt oder ein Fehler auftritt
}


int Player::getCurrentScore() const {
    QSqlQuery query;
    query.prepare("SELECT currentScore FROM benutzer WHERE id = :id");
    query.bindValue(":id", id); //
    if (query.exec()) {
        if (query.next()) {
            return query.value(0).toInt();
        }
    }
    return 0;
}

int Player::getLifelines() const {
    QSqlQuery query;
    query.prepare("SELECT lifelines FROM benutzer WHERE id = :id");
    query.bindValue(":id", id); //
    if (query.exec()) {
        if (query.next()) {
            return query.value(0).toInt();
        }
    }
    return 0;
}

void Player::updateScore(int newScore) {
    currentScore = newScore;
    if (newScore > bestScore) {
        bestScore = newScore;
    }
    QSqlQuery query;
    query.prepare("UPDATE benutzer "
                  "SET Highscore = :bestScore "
                  "WHERE id = :id");

    query.bindValue(":bestScore", bestScore); // Hier wird der Platzhalter :bestScore mit dem Wert von bestScore ersetzt
    query.bindValue(":id", id); // Hier wird der Platzhalter :id mit dem Wert von id ersetzt
    query.exec();
}



void Player::useLifeline() {
    if (lifelines > 0) {
        lifelines--;
    }
}
