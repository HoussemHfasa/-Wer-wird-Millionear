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

    void starteSpiel(const std::string& schwierigkeitsgrad, const std::string& kategorie);
    void beendeSpiel();
    void naechsteFrage();
    void waehleAntwort(int antwortIndex);
    void waehleSchwierigkeitsgrad(const string& schwierigkeitsgrad);
    void waehleKategorie(const string& kategorie);
    void AntwortSpieler(const char& AntwortSpieler1);
    Frage getAktuelleFrage();
    string gewaehlterSchwierigkeitsgrad;
    string gewaehlteKategorie;
    char benutzerAntwort;
    vector<Frage> vorbereiteteFragen(const std::string& schwierigkeitsgrad, const std::string& kategorie);

private:

    Player& spieler;
    vector<Frage> fragen;
    int aktuelleFrageIndex;
    vector<Frage> vorbereiteteFragen();
    vector<int> gewinnstufen;
    Frage& getAktuelleFrage() const;
    Lifeline lifeline;

};


#endif // GAMESESSION_H
