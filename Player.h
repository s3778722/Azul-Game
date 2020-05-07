#ifndef PLAYER_H
#define PLAYER_H

#include <string>
//#include "Mosaics.h"

class Player{
public:
    Player();
    Player(std::string name); 
    Player(std::string name, int score, bool isTurn);
    int getScore();
    std::string getName();
    bool getTurn();    
    void addPoints(int points);

    
private:
    std::string name;
    int score;
    bool isTurn;
    //Mosaic moziac;

};
#endif //PLAYER_H