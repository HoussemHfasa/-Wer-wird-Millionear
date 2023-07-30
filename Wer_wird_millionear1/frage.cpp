#include "Frage.h"

// Implementierung des Konstruktors
Frage::Frage(int frageID, const std::string& frage, const std::string& antwort1,
             const std::string& antwort2, const std::string& antwort3, const std::string& antwort4,
             char richtigeAntwort, const std::string& kategorie)
    : frageID(frageID), frage(frage), antwort1(antwort1), antwort2(antwort2),
      antwort3(antwort3), antwort4(antwort4), richtigeAntwort(richtigeAntwort), kategorie(kategorie) {}

// Implementierung der Methode zur Abfrage der Frage
std::string Frage::getFrage() const {
    return frage;
}

// Implementierung der Methode zur Abfrage der Antworten
std::vector<std::string> Frage::getAntworten() const {
    return {antwort1, antwort2, antwort3, antwort4};
}

// Implementierung der Methode zur Abfrage der richtigen Antwort
char Frage::getRichtigeAntwort() const {
    return richtigeAntwort;
}

// Implementierung der Methode zur Abfrage der Kategorie
std::string Frage::getKategorie() const {
    return kategorie;
}

// Implementierung der Methode zum Überprüfen einer gegebenen Antwort
bool Frage::istAntwortKorrekt(char benutzerAntwort) const {
    return benutzerAntwort == richtigeAntwort;
}
