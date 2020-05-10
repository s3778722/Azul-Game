#ifndef PLAYER_H
#define PLAYER_H

#include <string>
//#include "Mosaics.h"
#include "FloorLine.h"
#include <iostream>

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
    //Mosaic moziac;
    FloorLine* playerFloorLine;

};
#endif //PLAYER_H