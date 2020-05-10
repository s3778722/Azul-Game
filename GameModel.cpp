#include "GameModel.h"

GameModel::GameModel(std::string player1Name, std::string player2Name){

    player1 = new Player(player1Name);
    player2 = new Player(player2Name);

    Factories = new FactoryTable();
    // lid = new BoxLid();
    //CREATE BROKEN LINE ASKDFJALKSDHFLAKSDJFLAKSJDFLAKSJDF

}

void GameModel::Play(){

    cout << "Let's Play!\n" << endl;
    DisplayGameboard(player1);

}

void GameModel::DisplayGameboard(Player* player){

    cout << "== Start Round ===" << endl;
    cout << "TURN FOR PLAYER:" << player->getName() <<  endl;
    cout << "Factories:" << endl;
    Factories->DisplayFactories();
    cout << "Mosaic for " << player->getName() << ":" << endl;
    //Player->displayGameboard();
    cout << "Broken:" << endl;
    // DISPLAYBROKEN LINE function. ASDFLJASDLFJALSDKJFALKSDF

}
