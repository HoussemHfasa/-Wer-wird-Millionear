#ifndef GAMESESSION_H
#define GAMESESSION_H

#include "Player.h"
#include "Frage.h" // Frage-Klasse aus Ihrer vorherigen Implementierung
#include <vector>
#include <string>

class GameSession {
public:
    GameSession(Player& spieler);

    void starteSpiel();
    void beendeSpiel();
    void naechsteFrage();
    void waehleAntwort(int antwortIndex);
    void waehleSchwierigkeitsgrad(const std::string& schwierigkeitsgrad);
    void waehleKategorie(const std::string& kategorie);

private:
    Player& spieler;
    std::vector<Frage> fragen;
    int aktuelleFrageIndex;
    std::string gewaehlterSchwierigkeitsgrad;
    std::string gewaehlteKategorie;

    std::vector<Frage> fragenAusDatenbankHolen(const std::string& schwierigkeitsgrad, const std::string& kategorie);
};

#endif // GAMESESSION_H
