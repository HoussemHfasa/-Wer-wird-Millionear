#ifndef GAMESESSION_H
#define GAMESESSION_H
#include "lifelines.h"
#include "Player.h"
#include "Frage.h" // Frage-Klasse aus Ihrer vorherigen Implementierung
#include <vector>
#include <string>
using namespace std;
#include <list>
class GameSession {
public:
    GameSession(Player& spieler);

    void starteSpiel();
    void beendeSpiel();
    void naechsteFrage();
    void waehleAntwort(int antwortIndex);
    void waehleSchwierigkeitsgrad(const string& schwierigkeitsgrad);
    void waehleKategorie(const string& kategorie);

private:
    Player& spieler;
    vector<Frage> fragen;
    int aktuelleFrageIndex;
    string gewaehlterSchwierigkeitsgrad;
    string gewaehlteKategorie;
    vector<Frage> vorbereiteteFragen();
    vector<int> gewinnstufen;
    Lifeline lifeline;
};


#endif // GAMESESSION_H
