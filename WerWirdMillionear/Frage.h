#ifndef FRAGE_H
#define FRAGE_H

#include <string>
#include <vector>

class Frage {
private:
    int frageID;
    std::string frage;
    std::string antwort1;
    std::string antwort2;
    std::string antwort3;
    std::string antwort4;
    char richtigeAntwort;
    std::string kategorie;

public:
    Frage(int frageID, const std::string& frage, const std::string& antwort1,
          const std::string& antwort2, const std::string& antwort3, const std::string& antwort4,
          char richtigeAntwort, const std::string& kategorie);

    static Frage erstelleZufaelligeFrage(const std::string& kategorie, const std::string& schwierigkeit);

    std::string getFrage() const;
    std::vector<std::string> getAntworten() const;
    char getRichtigeAntwort() const;
    std::string getKategorie() const;
    bool istAntwortKorrekt(char benutzerAntwort) const;
    friend bool operator==(const Frage& frage1, const Frage& frage2);
};

#endif // FRAGE_H
