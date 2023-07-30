#include "Player.h"

Player::Player(const std::string& nickname, int bestScore, int currentScore, int lifelines)
    : nickname(nickname), bestScore(bestScore), currentScore(currentScore), lifelines(lifelines) {}

std::string Player::getNickname() const {
    return nickname;
}

int Player::getBestScore() const {
    return bestScore;
}

int Player::getCurrentScore() const {
    return currentScore;
}

int Player::getLifelines() const {
    return lifelines;
}

void Player::updateScore(int newScore) {
    currentScore = newScore;
    if (newScore > bestScore) {
        bestScore = newScore;
    }
}

void Player::useLifeline() {
    if (lifelines > 0) {
        lifelines--;
    }
}
