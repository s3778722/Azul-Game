#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "FloorLine.h"
#include <iostream>
#include "Mosaic.h"
#include "PatternLine.h"

class Player{
public:
    Player();
    ~Player();
    Player(std::string name); 
    Player(std::string name, int score, bool isTurn);
    int getScore();
    std::string getName();
    bool getTurn();    
    void addPoints(int points);
    void displayGameboard();
    FloorLine* getFloorLine();
    PatternLine* getPatternLine();
    Mosaic* getMosaic();
    void makeTileMosaicUppercase();

    
private:
    std::string name;
    int score;
    bool isTurn;
    Mosaic* mosaic;
    FloorLine* playerFloorLine;
    PatternLine* playerPatternLine;

};
#endif //PLAYER_H