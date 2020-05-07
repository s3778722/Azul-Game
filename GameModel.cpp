#include "GameModel.h"

GameModel::GameModel(std::string player1Name, std::string player2Name){

    player1 = new Player(player1Name);
    player2 = new Player(player2Name);

    FactoryTable* Factories = new FactoryTable();
    BoxLid* lid = new BoxLid();

}

void GameModel::Play(){

    cout << "Let's Play!\n" << endl;
    DisplayGameboard(player1);

}

void GameModel::DisplayGameboard(Player* player){

    cout << "== Start Round ===" << endl;
    cout << "TURN FOR PLAYER:" << player->getName() <<  endl;
    cout << "Factories:" << endl;
    //Factories->DisplayFactories();
    cout << "Mosaic for :" << endl;
    cout << "Broken:" << endl;

}
