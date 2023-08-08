#include <lifelines.h>
#include <iostream>
#include <vector>
#include <algorithm> // Für die Funktion std::random_shuffle
using namespace std;
#include <cstdlib>   // Für rand() und srand()
#include <numeric>

Lifeline::Lifeline() : fiftyFiftyUsed(false), audienceUsed(false), phoneUsed(false) {
    // Konstruktor
}


void Lifeline::fiftyFifty(const vector<string>& antworten, char richtigeAntwort) {
    if (!fiftyFiftyUsed) {
        vector<char> moeglicheAntworten = {'A', 'B', 'C', 'D'};
        moeglicheAntworten.erase(remove(moeglicheAntworten.begin(), moeglicheAntworten.end(), richtigeAntwort), moeglicheAntworten.end());

        // Zwei zufällige Antworten auswählen (eine richtige und eine falsche)
//random_shuffle(moeglicheAntworten.begin(), moeglicheAntworten.end());
        char antwort1 = moeglicheAntworten[0];
        char antwort2 = moeglicheAntworten[1];

        cout << "Der 50:50-Joker reduziert die Antwortmöglichkeiten auf '" << richtigeAntwort << "' und '" << antwort1 << "'.\n";
            fiftyFiftyUsed = true;
    } else {
        cout << "Der 50:50-Joker wurde bereits verwendet.\n";
    }
}


void Lifeline::audience(const std::vector<std::string>& antworten, char richtigeAntwort) {
    if (!audienceUsed) {
        int richtigeAntwortIndex = richtigeAntwort - 'A';
        vector<int> stimmen(antworten.size(), 0);

        // Zufällige Stimmen simulieren (die richtige Antwort erhält mehr Stimmen)
        for (int i = 0; i < 100; i++) {
            int stimme = rand() % antworten.size();
            if (stimme == richtigeAntwortIndex) {
                stimmen[stimme] += 70;
            } else {
                stimmen[stimme] += 30;
            }
        }

        // Summe der Stimmen berechnen
        int summeStimmen = accumulate(stimmen.begin(), stimmen.end(), 0);

        // Prozentuale Anteile berechnen und die UI aktualisieren
        for (int i = 0; i < antworten.size(); i++) {
            int stimmenProzent = (stimmen[i] * 100) / summeStimmen;
            // Die UI aktualisieren, um den berechneten Prozentsatz neben dem entsprechenden QPushButton anzuzeigen
        }

        audienceUsed = true;
    } else {
        cout << "Der Publikumsjoker wurde bereits verwendet.\n";
    }
}

std::vector<int> Lifeline::getAudienceStimmenProzent() const {
    return stimmenProzent;
}



void Lifeline::phone(const std::vector<std::string>& antworten, char richtigeAntwort) {
    if (!phoneUsed) {
        freundRat = string(1, richtigeAntwort);
        cout << "Ein Freund am Telefon sagt: " << freundRat << "\n";
        phoneUsed = true;
    } else {
        cout << "Der Telefonjoker wurde bereits verwendet.\n";
    }
}

// Getter-Methode für die Antwort des Freundes
string Lifeline::getPhoneAntwort() const {
    return freundRat;
}

bool Lifeline::isFiftyFiftyUsed() const {
    return fiftyFiftyUsed;
}

bool Lifeline::isAudienceUsed() const {
    return audienceUsed;
}

bool Lifeline::isPhoneUsed() const {
    return phoneUsed;
}
