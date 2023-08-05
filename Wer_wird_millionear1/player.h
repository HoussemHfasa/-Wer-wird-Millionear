
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;
class Player {
public:
   Player(const string& nickname);
   void addToDatabase();
    // Methoden zur Abfrage von Informationen

    string getNickname() const;
    int getBestScore() const;
    int getCurrentScore() const;
    int getLifelines() const;

    // Methoden zur Aktualisierung der Informationen
    void updateScore(int newScore);
    void useLifeline();

private:
    int id;
    int generateID(); // Hilfsmethode zur Generierung der ID
    string nickname;
    int bestScore;
    int currentScore;
    int lifelines;
};

#endif // PLAYER_H

