#include "GameModel.h"

GameModel::GameModel(std::string player1Name, std::string player2Name){

    player1 = new Player(player1Name);
    player2 = new Player(player2Name);
    Factories = new FactoryTable();

}

GameModel::GameModel(Player* player1load, Player* player2load){

    std::cout << "IN HER";

    player1 = player1load;
    std::cout << player1->getName();
    player2 = player2load;
    Factories = new FactoryTable();

}

void GameModel::play(){

    std::cout << "Let's Play!\n" << std::endl;
    displayGameboard(player1);

}

void GameModel::displayGameboard(Player* player){

    std::cout << "== Start Round ===" << std::endl;
    std::cout << "TURN FOR PLAYER:" << player->getName() <<  std::endl;
    std::cout << "Factories:" << std::endl;
    Factories->displayFactories();
    std::cout << "Mosaic for " << player->getName() << ":" << std::endl;
    player->displayGameboard();

}
