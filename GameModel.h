#include <string>
#include <iostream>
#include "Player.h"
#include "FactoryTable.h"
#include "BoxLid.h"

class GameModel{

public:
    
    GameModel();
    GameModel(std::string player1, std::string player2);
    void play();
    void displayGameboard(Player* player);

private:

    FactoryTable* Factories;
    Player* player1;
    Player* player2;
    // BoxLid* lid;

};