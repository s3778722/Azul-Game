#include <string>
#include <iostream>
#include "fstream"
#include "Player.h"
#include "FactoryTable.h"
#include "BoxLid.h"
#include "TileBag.h"

class GameModel{

public:
    
    GameModel(std::string player1, std::string player2);
    GameModel(std::string player1, std::string player2,int seed);
    GameModel(Player* player1, Player* player2,FactoryTable* factories, TileBag* tileBag, BoxLid* boxLidLoad);
    ~GameModel();
    void play();
    void displayGameboard(Player* player);
    void saveGame(std::string saveFileName);
    void commandParse(std::string command, Player* player);
    void fillFactories();
    bool drawTileFromFactoryToPatternLine(int factory, Colour colour, int atPatternLine, Player* player);
    bool playSupportFunction(Player* player, Player* otherPlayer,std::string command);
    bool endGameConditionCheck();

private:

    void savePlayerData(Player* player, std::ofstream& saveFile);

    FactoryTable* Factories;
    Player* player1;
    Player* player2;
    BoxLid* boxLid;
    TileBag* tileBag;
    bool roundComplete = false; //TODO REMOVE THIS DAM THING AND WHEREVER ELSE I SAID TO
};