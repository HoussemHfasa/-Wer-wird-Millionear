#include <iostream>
#include "Frage.h"

int main() {
    // Beispiel: Erstellen einer Frage
    Frage frage1(1, "Wie viele Kontinente gibt es?", "3", "5", "7", "6", 'b', "Allgemeinwissen");

    // Beispiel: Abrufen der Frage und Antworten
    std::cout << "Frage: " << frage1.getFrage() << std::endl;
    std::vector<std::string> antworten = frage1.getAntworten();
    std::cout << "Antwort 1: " << antworten[0] << std::endl;
    std::cout << "Antwort 2: " << antworten[1] << std::endl;
    std::cout << "Antwort 3: " << antworten[2] << std::endl;
    std::cout << "Antwort 4: " << antworten[3] << std::endl;

    // Beispiel: Überprüfen der Antwort
    char benutzerAntwort;
    std::cout << "Geben Sie die Buchstaben der richtigen Antwort ein (a/b/c/d): ";
    std::cin >> benutzerAntwort;

    if (frage1.istAntwortKorrekt(benutzerAntwort)) {
        std::cout << "Richtig!" << std::endl;
    } else {
        std::cout << "Falsch!" << std::endl;
    }

    return 0;
}
