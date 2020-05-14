#include "GameModel.h"

GameModel::GameModel(std::string player1Name, std::string player2Name){

    player1 = new Player(player1Name);
    player2 = new Player(player2Name);
    Factories = new FactoryTable();
    tileBag = new TileBag();
    boxLid = new BoxLid();

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

    // TODO
    std::cout << "== END OF ROUND ===" << std::endl;
    //this must be called after each round automatically or 'have the user put in "save" and be called' (single quote is the way the specs show)
    // saveGame(savedGameFile.txt);

}

void GameModel::saveGame(std::string saveFileName){
    std::ofstream saveFile(saveFileName);
    saveFile.clear();//not sure if this is needed but i'll put here
    
    for (int i = 0; i < Factories->getSize(); i++){ //factories
        for(int j=0; j<Factories->getFactory(i).size(); j++){
            saveFile << Factories->getTable().at(i).at(j)->getColour();
            if(j < Factories->getFactory(i).size()-1){
                saveFile << " ";
            }
        }
        saveFile << std::endl;
    }
    
    saveFile << std::endl;
    
    for(int i=0;i<tileBag->bagSize();i++){ // tilebag
        saveFile << tileBag->getTile(i)->getColour();
        if(i < tileBag->bagSize()-1){
                saveFile << " ";
        }
    }

    for(int i=0; i<boxLid->size();i++){ //boxlid
        saveFile << boxLid->getBoxLid().at(i);
        if(i < boxLid->size()-1){
                saveFile << " ";
        }
    }

    saveFile << std::endl;
    
    savePlayerData(player1,saveFile);
    savePlayerData(player2,saveFile);
    saveFile.close();
    std::cout << "Game successfully saved to ’" << saveFileName << "’" << std::endl;
}

void GameModel::savePlayerData(Player* player, std::ofstream& saveFile){
    saveFile << player->getName() << std::endl;
    saveFile << player->getTurn() << std::endl;
    saveFile << player->getScore() << std::endl << std::endl;

    Tile*** mosaicGrid = player->getMosaic()->getMosaic();
    Tile*** patternLineGrid = player->getPatternLine()->getTilePatternLine();
    LinkedList* floorLine = player->getFloorLine()->getFloorLine();

    for(int i=0;i<5;i++){ // pattern line
        for(int j=0; j<i+1; j++){
            saveFile << patternLineGrid[i][j]->getColour();
            if(j < i){
                saveFile << " ";
            }
        }
        saveFile << std::endl;
    }

    saveFile << std::endl;

    for(int i=0;i<5;i++){ // mosaic/board/wall
        for(int j=0; j<5; j++){
            saveFile << mosaicGrid[i][j]->getColour();
            if(j < i){
                saveFile << " ";
            }
        }
        saveFile << std::endl;
    }

    saveFile << std::endl;

    int size = floorLine->getSize(); // floorline/broken tiles
    if(size != 0){
        for(int i=0; i<size; i++){
            saveFile << floorLine->getTile(i)->getColour();
            if(i<size-1){
                saveFile << " ";
            }
        }
        saveFile << std::endl;
    }
    else{
        saveFile << std::endl;
    }


}
