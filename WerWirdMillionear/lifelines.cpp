#include <lifelines.h>
#include <iostream>
#include <vector>
#include <algorithm> // Für die Funktion std::random_shuffle
using namespace std;
#include <cstdlib>   // Für rand() und srand()

// Konstruktor der Lifeline-Klasse, initialisiert die Zustände der Joker
Lifeline::Lifeline() : fiftyFiftyUsed(false), audienceUsed(false), phoneUsed(false) {
    // Konstruktor
}

// Methode zur Verwendung des "50:50-Jokers"
void Lifeline::fiftyFifty([[maybe_unused]] const vector<string>& antworten, char richtigeAntwort) {
    if (!fiftyFiftyUsed) {
        vector<char> moeglicheAntworten = {'A', 'B', 'C', 'D'};
        // Die richtige Antwort aus den möglichen Antworten entfernen
        moeglicheAntworten.erase(remove(moeglicheAntworten.begin(), moeglicheAntworten.end(), richtigeAntwort), moeglicheAntworten.end());
        fiftyFiftyUsed = true; // Markieren, dass der "50:50-Joker" verwendet wurde
    } else {
        // Falls der "50:50-Joker" bereits verwendet wurde, keine Aktion erforderlich
    }
}

// Methode zur Verwendung des "Publikumsjokers"
void Lifeline::audience(const vector<string>& antworten, char richtigeAntwort) {
    if (!audienceUsed) {
        int richtigeAntwortIndex = richtigeAntwort - 'A';
        vector<int> stimmen(antworten.size(), 0);
        stimmenProzent.resize(antworten.size());

        // Simulieren von zufälligen Publikumsstimmen (richtige Antwort erhält mehr Stimmen)
        int summeStimmen = 0;
        int antwortsize = antworten.size();
        for (int i = 0; i < antwortsize; i++) {
            if (i == richtigeAntwortIndex) {
                stimmen[i] = rand() % 70 + 31; // Bereich 31-100 für die richtige Antwort
            } else {
                stimmen[i] = rand() % 30 + 1;  // Bereich 1-30 für falsche Antworten
            }
            summeStimmen += stimmen[i];
        }

        // Prozentsätze der Publikumsstimmen berechnen
        for (int i = 0; i < antwortsize; i++) {
            stimmenProzent[i] = (stimmen[i] * 100) / summeStimmen;
        }

        audienceUsed = true; // Markieren, dass der "Publikumsjoker" verwendet wurde
    } else {
        cout << "Der Publikumsjoker wurde bereits verwendet.\n";
    }
}

// Methode zur Rückgabe der Prozentsätze der Publikumsstimmen für den "Publikumsjoker"
vector<int> Lifeline::getAudienceStimmenProzent() const {
    return stimmenProzent;
}

// Methode zur Verwendung des "Telefonjokers"
void Lifeline::phone([[maybe_unused]] const vector<string>& antworten, char richtigeAntwort) {
    if (!phoneUsed) {
        // Der Freund gibt den Ratschlag basierend auf der richtigen Antwort
        freundRat = string(1, richtigeAntwort);
        cout << "Ein Freund am Telefon sagt: " << freundRat << "\n";
        phoneUsed = true; // Markieren, dass der Telefonjoker verwendet wurde
    } else {
        // Falls der Telefonjoker bereits verwendet wurde, keine Aktion erforderlich
    }
}


// Getter-Methode für die Antwort des Freundes
string Lifeline::getPhoneAntwort() const {
    return freundRat;
}

// Methode zur Überprüfung, ob die "50:50"-Joker bereits verwendet wurde
bool Lifeline::isFiftyFiftyUsed() const {
    return fiftyFiftyUsed;
}

// Methode zur Überprüfung, ob der "Publikumsjoker" bereits verwendet wurde
bool Lifeline::isAudienceUsed() const {
    return audienceUsed;
}

// Methode zur Überprüfung, ob der "Telefonjoker" bereits verwendet wurde
bool Lifeline::isPhoneUsed() const {
    return phoneUsed;
}

