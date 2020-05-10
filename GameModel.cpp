#include "GameModel.h"

GameModel::GameModel(std::string player1Name, std::string player2Name){

    player1 = new Player(player1Name);
    player2 = new Player(player2Name);
    Factories = new FactoryTable();

}

void GameModel::play(){

    cout << "Let's Play!\n" << endl;
    displayGameboard(player1);

}

void GameModel::displayGameboard(Player* player){

    cout << "== Start Round ===" << endl;
    cout << "TURN FOR PLAYER:" << player->getName() <<  endl;
    cout << "Factories:" << endl;
    Factories->displayFactories();
    cout << "Mosaic for " << player->getName() << ":" << endl;
    player->displayGameboard();
    cout << "Broken:" << endl;

}
