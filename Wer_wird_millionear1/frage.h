#ifndef FRAGE_H
#define FRAGE_H

#include <string>
#include <vector>

class Frage {
public:
    // Konstruktor
    Frage(int frageID, const std::string& frage, const std::string& antwort1,
          const std::string& antwort2, const std::string& antwort3, const std::string& antwort4,
          char richtigeAntwort, const std::string& kategorie);

    // Methoden zur Abfrage von Informationen
    std::string getFrage() const;
    std::vector<std::string> getAntworten() const;
    char getRichtigeAntwort() const;
    std::string getKategorie() const;

    // Methode zum Überprüfen einer gegebenen Antwort
    bool istAntwortKorrekt(char benutzerAntwort) const;

private:
    int frageID;
    std::string frage;
    std::string antwort1;
    std::string antwort2;
    std::string antwort3;
    std::string antwort4;
    char richtigeAntwort;
    std::string kategorie;
};

#endif // FRAGE_H
