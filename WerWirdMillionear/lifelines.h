#ifndef LIFELINES_H
#define LIFELINES_H
using namespace std;
#include <vector>
#include <string>

class Lifeline {
public:
    // Konstruktor
    Lifeline();

    // 50:50-Joker
    void fiftyFifty(const vector<string>& antworten, char richtigeAntwort);

    // Publikumsjoker
    void audience(const std::vector<std::string>& antworten, char richtigeAntwort);

    // Telefonjoker
    void phone(const std::vector<std::string>& antworten, char richtigeAntwort);
    std::string getPhoneAntwort() const; // Keine zusätzliche Qualifikation hier

    // Prüfen, ob die 50:50-Joker verwendet wurde
    bool isFiftyFiftyUsed() const;

    // Prüfen, ob der Publikumsjoker verwendet wurde
    bool isAudienceUsed() const;

    // Prüfen, ob der Telefonjoker verwendet wurde
    bool isPhoneUsed() const;
    vector<int> getAudienceStimmenProzent() const;


private:
    bool fiftyFiftyUsed;
    bool audienceUsed;
    bool phoneUsed;
    vector<int> stimmenProzent;
    string freundRat;
};

#endif // LIFELINES_H
