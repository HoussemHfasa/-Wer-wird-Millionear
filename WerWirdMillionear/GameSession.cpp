#include "GameSession.h"
#include "lifelines.h"
#include "player.h"
#include <algorithm> // Für die Funktion std::find
using namespace std;
#include <iostream>

// Konstruktor für eine Spielsitzung
GameSession::GameSession(Player& spieler) : spieler(spieler), aktuelleFrageIndex(0) {
    // Leeres Kategorie- und Schwierigkeitsgrad-Auswahl am Anfang
    gewaehlterSchwierigkeitsgrad = "";
    gewaehlteKategorie = "";

    // Gewinnstufen für das Spiel festlegen

    gewinnstufen = {50, 100, 200, 300, 500, 1000, 2000, 4000, 8000, 16000, 32000, 64000, 125000, 500000, 1000000};
}

// Methode zum Abrufen der aktuellen Frage

Frage GameSession::getAktuelleFrage() {
    return fragen[aktuelleFrageIndex];
}

// Methode zur Vorbereitung zufälliger Fragen basierend auf Schwierigkeitsgrad und Kategorie

vector<Frage> GameSession::vorbereiteteFragen(const string& schwierigkeitsgrad, const string& kategorie) {
    vector<Frage> vorbereiteteFragen;
    while (vorbereiteteFragen.size() < 15) {
        Frage zufaelligeFrage = Frage::erstelleZufaelligeFrage(kategorie, schwierigkeitsgrad);
        if (find(vorbereiteteFragen.begin(), vorbereiteteFragen.end(), zufaelligeFrage) == vorbereiteteFragen.end()) {
            vorbereiteteFragen.push_back(zufaelligeFrage);
        }
    }
    return vorbereiteteFragen;
}
