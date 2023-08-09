#ifndef FRAGE_H
#define FRAGE_H

#include <string>
#include <vector>
using namespace std;

class Frage {
private:
    int frageID;
    string frage;
    string antwort1;
    string antwort2;
    string antwort3;
    string antwort4;
    char richtigeAntwort;
    string kategorie;

public:
    Frage(int frageID, const string& frage, const string& antwort1,
          const string& antwort2, const string& antwort3, const string& antwort4,
          char richtigeAntwort, const string& kategorie);

    static Frage erstelleZufaelligeFrage(const string& kategorie, const string& schwierigkeit);

    string getFrage() const;
    vector<string> getAntworten() const;
    char getRichtigeAntwort() const;
    string getKategorie() const;
    bool istAntwortKorrekt(char benutzerAntwort) const;
    friend bool operator==(const Frage& frage1, const Frage& frage2);
};

#endif // FRAGE_H
