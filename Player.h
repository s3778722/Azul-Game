#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>
#include "Mosaic.h"

class Player{
public:
    Player();
    Player(std::string name); 
    Player(std::string name, int score, bool isTurn);
    int getScore();
    std::string getName();
    bool getTurn();    
    void addPoints(int points);
    void displayGameboard();

    
private:
    std::string name;
    int score;
    bool isTurn;
    Mosiac* mosiac;

};
#endif //PLAYER_H