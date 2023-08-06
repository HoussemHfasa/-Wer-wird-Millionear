#ifndef LIFELINES_H
#define LIFELINES_H

#include <vector>
#include <string>

class Lifeline {
public:
    // Konstruktor
    Lifeline();

    // 50:50-Joker
    void fiftyFifty(const std::vector<std::string>& antworten, char richtigeAntwort);

    // Publikumsjoker
    void audience(const std::vector<std::string>& antworten, char richtigeAntwort);

    // Telefonjoker
    void phone(const std::vector<std::string>& antworten, char richtigeAntwort);

    // Prüfen, ob die 50:50-Joker verwendet wurde
    bool isFiftyFiftyUsed() const;

    // Prüfen, ob der Publikumsjoker verwendet wurde
    bool isAudienceUsed() const;

    // Prüfen, ob der Telefonjoker verwendet wurde
    bool isPhoneUsed() const;

private:
    bool fiftyFiftyUsed;
    bool audienceUsed;
    bool phoneUsed;
};

#endif // LIFELINES_H
