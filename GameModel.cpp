#include "GameModel.h"

GameModel::GameModel(std::string player1Name, std::string player2Name){

    player1 = new Player(player1Name);
    player1->setIsTurn(true);
    player2 = new Player(player2Name);
    Factories = new FactoryTable();
    tileBag = new TileBag();
    boxLid = new BoxLid();
    patternLine = new PatternLine();

}

GameModel::GameModel(Player* player1load, Player* player2load, FactoryTable* factories, TileBag* tileBag,BoxLid* boxLidLoad){

    std::cout << "IN HER";

    player1 = player1load;
    player2 = player2load;
    this->Factories = factories;
    this->tileBag = tileBag;
    this->boxLid = boxLidLoad;

}

void GameModel::play(){
    
    std::cin.ignore();
    std::cout << "Let's Play!\n" << std::endl;
    
    bool winner = false;
    while(!winner){

        bool roundComplete = false;
        std::cout << "=== Start Round == " << std::endl;
        if(!Factories->factoriesLoaded()){
            fillFactories();//this should only be called if the factories are empty and it is a new game
        }

        while(!roundComplete){

            std::string command;
        
            if(player1->getTurn()){

                bool turnComplete = false;

                while (!turnComplete){

                    std::cout << "TURN FOR PLAYER: " << player1->getName() << std::endl;
                    Factories->displayFactories();
                    player1->displayGameboard();
                    std::cout << "> ";
                    std::getline(std::cin, command);
                    if(command == "save"){
                        std::string fileName = "";
                        std::cout << "Enter the file name(eg: save.txt): ";
                        std::cin >> fileName;
                        saveGame(fileName);
                    }
                    else{
                        commandParse(command, player1);
                    }
                    if (player1->getTurn() == false){
                        player2->setIsTurn(true);
                        turnComplete = true;
                    }
                }
            }

            bool turnComplete = false;

            while (!turnComplete){
                std::cout << "TURN FOR PLAYER: " << player2->getName() << std::endl;
                Factories->displayFactories();
                player2->displayGameboard();
                std::cout << "> ";
                std::getline(std::cin, command);
                if(command == "save"){
                        std::string fileName = "";
                        std::cout << "Enter the file name(eg: save.txt): ";
                        std::cin >> fileName;
                        saveGame(fileName);
                }
                else{
                    commandParse(command, player1);
                }
                if (player2->getTurn() == false){
                    player1->setIsTurn(true);
                    turnComplete = true;
                }
            }

        }

        std::cout << "=== END OF ROUND ===" << std::endl;

    }

    std::cout << "=== GAME OVER ===" << std::endl;

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
        for(unsigned int j=0; j<Factories->getFactory(i).size(); j++){
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
    
    if(boxLid->size() == 0){
        std::cout<<"comes here"<<std::endl;
        saveFile << std::endl;
    }
    else{
        for(int i=0; i<boxLid->size();i++){ //boxlid
            saveFile << boxLid->getBoxLid().at(i);
            if(i < boxLid->size()-1){
                    saveFile << " ";
            }
        }
    }

    saveFile << std::endl;
    saveFile << std::endl;
    
    savePlayerData(player1,saveFile);
    saveFile << std::endl;
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
            saveFile << " ";
            // if(j < i){
            //     saveFile << " ";
            // }
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

void GameModel::commandParse(std::string command, Player* player){ //need renaming the function

    if (command == "help"){ // can be extended for specific help later if wanted

        std::cout << "I AM HELP, LOOK AT ME" << std::endl;

    }

    else if (command == "switch"){ // just a tester

        player->setIsTurn(false);

    }

    else if (command.substr(0,4) == "turn"){

        if ((command.substr(4,1) == " " && command.length() == 10 ) && (command.substr(6,1) == " " && command.substr(8,1) == " ")){ // checks for spaces in the right spot and proper length

            std::string factoryStr = command.substr(5,1);
            std::string colourStr = command.substr(7,1);
            std::string patternRowStr = command.substr(9,1);

            // player place tile function() returns bool, if false should provide error too other than the one i put below.


            bool placeTileSuccess = true;

            //if placeTileSuccess(player, factory, colour, pattern) <- this is converted from the string ones above
            if(placeTileSuccess){ // replace this with the method above.
                player->setIsTurn(false); // goes to the next player now
            }

            else{
                std::cout << "Tile Couldn't be placed." <<  std::endl;
            }
        }
    }
}

void GameModel::fillFactories(){

    Factories->getFactory(0).at(0)->setColour('F');

    for (int i = 1; i < 6; i++){

        for (int j = 0; j < 4; j++){

            // std::cout << "RAN";
            Tile* tilePtr = tileBag->drawTileFront();
            Factories->getFactory(i).at(j)->setColour(tilePtr->getColour()); 
            delete tilePtr; 
            //std::cout << tileBag->drawTileFront()->getColour(); CHECK THIS FUNCTION, THIS SHOULD RETURN THE TILE CHAR, DOESN'T

        }
    }
}
//doesn't include picking First Player Tile, and putting additional tile to floorline
bool GameModel::drawTileFromFactoryToPatternLine(int factory, Colour colour, int atPatternLine){
    bool moved = false;
    if (factory > 0){
        for (int i = 0; i < 5; i++)
        {
            if (Factories->getFactory(factory).at(i)->getColour() == colour){
                this->Factories->getFactory(factory).at(i)->setColour(' ');
                for (int column = 0; column < 5; column++)
                {
                    if (patternLine->getTilePatternLine()[atPatternLine][column]->getColour() == NO_TILE)
                    {
                        patternLine->getTilePatternLine()[atPatternLine][column]->setColour(colour);
                        moved =  true;
                    }
                }
            }
            else{
                Tile* x = new Tile(Factories->getFactory(factory).at(i)->getColour());
                this->Factories->getFactory(factory).at(i)->setColour(' ');
                this->Factories->getFactory(0).push_back(x);
                moved =  true;
            }
        }
    }
    else if (factory == 0){
        for (int i = 0; i < 5; i++)
        {
            if (Factories->getFactory(factory).at(i)->getColour() == colour){
                this->Factories->getFactory(factory).at(i)->setColour(' ');
                //not sure how to dynamicly get the count of factory, as max is not 5, needed to be fix
                for (int column = 0; column < 5; column++)
                {
                    if (patternLine->getTilePatternLine()[atPatternLine][column]->getColour() == NO_TILE)
                    {
                        patternLine->getTilePatternLine()[atPatternLine][column]->setColour(colour);
                        moved =  true;
                    }
                }
            }
        }
    }
    else{
        moved =  false;
    }
    return moved;
}

