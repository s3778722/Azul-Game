#include "GameModel.h"

GameModel::GameModel(std::string player1Name, std::string player2Name){

    player1 = new Player(player1Name);
    player2 = new Player(player2Name);

    Factories = new FactoryTable();
    // lid = new BoxLid();
    //CREATE BROKEN LINE ASKDFJALKSDHFLAKSDJFLAKSJDFLAKSJDF

}

void GameModel::Play(){

    std::cout << "Let's Play!\n" << std::endl;
    DisplayGameboard(player1);

}

void GameModel::DisplayGameboard(Player* player){

    std::cout << "== Start Round ===" << std::endl;
    std::cout << "TURN FOR PLAYER:" << player->getName() <<  std::endl;
    std::cout << "Factories:" << std::endl;
    Factories->DisplayFactories();
    std::cout << "Mosaic for " << player->getName() << ":" << std::endl;
    player->displayGameboard();

}
