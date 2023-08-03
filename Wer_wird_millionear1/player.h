
#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
public:
   Player(const std::string& nickname);
   void addToDatabase();
    // Methoden zur Abfrage von Informationen

    std::string getNickname() const;
    int getBestScore() const;
    int getCurrentScore() const;
    int getLifelines() const;

    // Methoden zur Aktualisierung der Informationen
    void updateScore(int newScore);
    void useLifeline();

private:
    int id;
    int generateID(); // Hilfsmethode zur Generierung der ID
    std::string nickname;
    int bestScore;
    int currentScore;
    int lifelines;
};

#endif // PLAYER_H

