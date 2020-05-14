#include <string>
#include <iostream>
#include "fstream"
#include "Player.h"
#include "FactoryTable.h"
#include "BoxLid.h"
#include "TileBag.h"

class GameModel{

public:
    
    GameModel();
    GameModel(std::string player1, std::string player2);
    GameModel(Player* player1, Player* player2);
    void play();
    void displayGameboard(Player* player);
    void saveGame(std::string saveFileName);

private:

    void savePlayerData(Player* player, std::ofstream& saveFile);

    FactoryTable* Factories;
    Player* player1;
    Player* player2;
    BoxLid* boxLid;
    TileBag* tileBag;

};