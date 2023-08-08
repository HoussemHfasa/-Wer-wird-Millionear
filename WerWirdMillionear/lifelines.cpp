#include <lifelines.h>
#include <iostream>
#include <vector>
#include <algorithm> // Für die Funktion std::random_shuffle
using namespace std;
#include <cstdlib>   // Für rand() und srand()
#include <numeric>
#include <QtWidgets/QPushButton>
#include <QString>
#include <QWidget>


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
         stimmenProzent.resize(antworten.size());
        // Zufällige Stimmen simulieren (die richtige Antwort erhält mehr Stimmen)
        int summeStimmen = 0;
        for (int i = 0; i < antworten.size(); i++) {
            if (i == richtigeAntwortIndex) {
                stimmen[i] = rand() % 70 + 31; // Bereich 31-100 für die richtige Antwort
            } else {
                stimmen[i] = rand() % 30 + 1;  // Bereich 1-30 für falsche Antworten
            }
            summeStimmen += stimmen[i];
        }

        // Prozentsätze berechnen
        for (int i = 0; i < antworten.size(); i++) {
            stimmenProzent[i] = (stimmen[i] * 100) / summeStimmen;
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
