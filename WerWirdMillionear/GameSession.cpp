#include "GameSession.h"
#include "lifelines.h"
#include "player.h"
#include <algorithm> // Für die Funktion std::find
using namespace std;
#include <iostream>

GameSession::GameSession(Player& spieler) : spieler(spieler), aktuelleFrageIndex(0) {
    // Leeres Kategorie- und Schwierigkeitsgrad-Auswahl am Anfang
    gewaehlterSchwierigkeitsgrad = "";
    gewaehlteKategorie = "";


    // Fragen vorbereiten (15 zufällige Fragen, ohne Wiederholung)

    gewinnstufen = {50, 100, 200, 300, 500, 1000, 2000, 4000, 8000, 16000, 32000, 64000, 125000, 500000, 1000000};
}

void GameSession::starteSpiel() {
    fragen = vorbereiteteFragen(gewaehlteKategorie, gewaehlterSchwierigkeitsgrad);

    // Dann die vorbereiteten Fragen abrufen

    if (fragen.empty()) {
        // Wenn keine Fragen gefunden wurden, das Spiel beenden
        beendeSpiel();
        return;
    }

    // Erste Frage anzeigen
    cout << "Willkommen bei 'Wer wird Millionär'!\n\n";
        naechsteFrage();
}

void GameSession::beendeSpiel() {
    cout << "Das Spiel ist vorbei!\n";
    cout << "Dein Score: " << spieler.getCurrentScore() << "\n";
    cout << "Dein bester Score: " << spieler.getBestScore() << "\n";
}

Frage GameSession::getAktuelleFrage() {
    return fragen[aktuelleFrageIndex];
}

void GameSession::naechsteFrage() {
    while (aktuelleFrageIndex < fragen.size()) {
        Frage& aktuelleFrage = fragen[aktuelleFrageIndex];

        // ... Überprüfen und Verwenden der Lifelines ...

        cout << "Frage: " << aktuelleFrage.getFrage() << "\n";

        vector<string> antworten = aktuelleFrage.getAntworten();
        for (int i = 0; i < antworten.size(); i++) {
            cout << char('A' + i) << ": " << antworten[i] << "\n";
        }

        char benutzerAntwort;
        //cout << "Bitte wähle deine Antwort (A, B, C oder D): ";
               // cin >> benutzerAntwort;

        if (aktuelleFrage.istAntwortKorrekt(benutzerAntwort)) {
            int gewinn = gewinnstufen[aktuelleFrageIndex]; // Gewinnstufe für die aktuelle Frage
            cout << "Richtig! Du erhältst " << gewinn << " Punkte.\n";
            spieler.updateScore(spieler.getCurrentScore() + gewinn);
        } else {
            cout << "Leider falsch. Das Spiel ist vorbei.\n";
            beendeSpiel();
            return;
        }

        aktuelleFrageIndex++;
    }

    cout << "Herzlichen Glückwunsch! Du hast alle Fragen beantwortet.\n";
        beendeSpiel();
}


void GameSession::waehleSchwierigkeitsgrad(const string& schwierigkeitsgrad) {
        gewaehlterSchwierigkeitsgrad = schwierigkeitsgrad;
}

void GameSession::waehleKategorie(const string& kategorie) {
        gewaehlteKategorie = kategorie;
}

vector<Frage> GameSession::vorbereiteteFragen(const std::string& schwierigkeitsgrad, const std::string& kategorie) {
    vector<Frage> vorbereiteteFragen;
    while (vorbereiteteFragen.size() < 15) {
        Frage zufaelligeFrage = Frage::erstelleZufaelligeFrage(kategorie, schwierigkeitsgrad);
        if (find(vorbereiteteFragen.begin(), vorbereiteteFragen.end(), zufaelligeFrage) == vorbereiteteFragen.end()) {
            vorbereiteteFragen.push_back(zufaelligeFrage);
        }
    }
    return vorbereiteteFragen;
}
