#include <string>
#include <iostream>
#include "Player.h"
#include "FactoryTable.h"
#include "BoxLid.h"

using std::cout;
using std::endl;

class GameModel{

public:
    
    GameModel();
    GameModel(std::string player1, std::string player2);
    void Play();
    void DisplayGameboard(Player* player);

private:

    FactoryTable* Factories;
    Player* player1;
    Player* player2;
    BoxLid* lid;

};