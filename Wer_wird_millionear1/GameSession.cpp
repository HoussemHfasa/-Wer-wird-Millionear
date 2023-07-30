#include "GameSession.h"

GameSession::GameSession(Player& spieler) : spieler(spieler), aktuelleFrageIndex(0) {}

void GameSession::starteSpiel() {
    // Setze Standard-Schwierigkeitsgrad und Kategorie hier, falls erforderlich
    fragen = fragenAusDatenbankHolen(gewaehlterSchwierigkeitsgrad, gewaehlteKategorie);
    aktuelleFrageIndex = 0;
    // TODO: Zeige Willkommensnachricht oder Anweisungen an den Spieler
    // TODO: Zeige dem Spieler die erste Frage an
}

void GameSession::beendeSpiel() {
    // TODO: Zeige Abschlussnachricht, Punktestand usw. an
}

void GameSession::naechsteFrage() {
    aktuelleFrageIndex++;
    if (aktuelleFrageIndex < fragen.size()) {
        // TODO: Zeige dem Spieler die nächste Frage an
    } else {
        // Keine weiteren Fragen, beende das Spiel
        beendeSpiel();
    }
}

void GameSession::waehleAntwort(int antwortIndex) {
    if (aktuelleFrageIndex < fragen.size()) {
        Frage& aktuelleFrage = fragen[aktuelleFrageIndex];
        if (aktuelleFrage.istAntwortKorrekt(aktuelleFrage.getAntworten()[antwortIndex])) {
            // TODO: Behandlung für korrekte Antwort
        } else {
            // TODO: Behandlung für falsche Antwort
        }
        // Gehe zur nächsten Frage
        naechsteFrage();
    }
}

void GameSession::waehleSchwierigkeitsgrad(const std::string& schwierigkeitsgrad) {
    gewaehlterSchwierigkeitsgrad = schwierigkeitsgrad;
}

void GameSession::waehleKategorie(const std::string& kategorie) {
    gewaehlteKategorie = kategorie;
}

std::vector<Frage> GameSession::fragenAusDatenbankHolen(const std::string& schwierigkeitsgrad, const std::string& kategorie) {
    // TODO: Implementiere die Logik, um Fragen aus der Datenbank abzurufen
    // basierend auf dem gewählten Schwierigkeitsgrad und der Kategorie.
    // Gib einen Vektor von Frage-Objekten zurück, die aus der Datenbank erhalten wurden.
    // Zum Beispiel können Sie SQL-Abfragen verwenden, um die Fragen abzurufen.
    // Ersetze diese Implementierung durch deine eigentliche Datenbank-Abfrage-Logik.
    return std::vector<Frage>();
}
