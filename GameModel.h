#include <string>
#include <iostream>
#include "fstream"
#include "Player.h"
#include "FactoryTable.h"
#include "BoxLid.h"
#include "TileBag.h"

class GameModel{

public:
    
    //constructor new game
    GameModel(std::string player1, std::string player2);
    //overloaded constructor new game with seed
    GameModel(std::string player1, std::string player2,int seed);
    //overloaded constructor for loaded game
    GameModel(Player* player1, Player* player2,FactoryTable* factories, TileBag* tileBag, BoxLid* boxLidLoad);
    // destructor
    ~GameModel();
    // start game play
    void play();
    // display game board
    void displayGameboard(Player* player);
    // save game data
    void saveGame(std::string saveFileName);
    // manage the game input commands
    void commandParse(std::string command, Player* player);
    // fill the factories from the tile bag
    void fillFactories();
    // move from factory to the pattern line
    bool drawTileFromFactoryToPatternLine(int factory, Colour colour, int atPatternLine, Player* player);
    // game play suppor function
    bool playSupportFunction(Player* player, Player* otherPlayer,std::string command);
    // check if the game end conditions are met
    bool endGameConditionCheck();

private:
    //player data saving support function
    void savePlayerData(Player* player, std::ofstream& saveFile);

    FactoryTable* Factories;
    Player* player1;
    Player* player2;
    BoxLid* boxLid;
    TileBag* tileBag;
    bool roundComplete = false; // This two booleans shouldn't be required here. and this really
    bool quit = false;          // isn't optimal, but was a quick fix to be accessible from multiple methods. 
                                // Realistically, this should not be needed here but now is required
                                // as the code depends on this variable existing in multiple areas.
};