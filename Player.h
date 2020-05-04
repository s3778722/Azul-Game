#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player{
public:
    Player();
    Player(std::string name); 
    Player(std::string name, int score, bool isTurn);
    int Player::getScore();
    std::string Player::getName();
    bool Player::getTurn();
    
private:
    std::string name;
    int score;
    bool isTurn;

};
#endif //PLAYER_H