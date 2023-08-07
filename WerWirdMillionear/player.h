
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

    // Methoden zur Aktualisierung der Informationen
    void updateScore(int newScore);
     void getAllPlayers();

private:
    string nickname;
    int bestScore;
    int currentScore;
};

#endif // PLAYER_H

