#include "GameModel.h"

GameModel::GameModel(std::string player1Name, std::string player2Name){

    player1 = new Player(player1Name);
    player1->setIsTurn(true);
    player2 = new Player(player2Name);
    Factories = new FactoryTable();
    tileBag = new TileBag();
    boxLid = new BoxLid();
    roundComplete = false; //TODO REMOVE THIS DAM THING AND WHEREVER ELSE I SAID TO

}

GameModel::GameModel(std::string player1Name, std::string player2Name,int seed){

    player1 = new Player(player1Name);
    player1->setIsTurn(true);
    player2 = new Player(player2Name);
    Factories = new FactoryTable();
    tileBag = new TileBag(seed);
    boxLid = new BoxLid();
    roundComplete = false;
}

GameModel::GameModel(Player* player1load, Player* player2load, FactoryTable* factories, TileBag* tileBag,BoxLid* boxLidLoad){

    player1 = player1load;
    player2 = player2load;
    this->Factories = factories;
    this->tileBag = tileBag;
    this->boxLid = boxLidLoad;
    roundComplete = false;

}

GameModel::~GameModel(){

}

void GameModel::play(){
    
    std::cin.ignore();
    std::cout << "Let's Play!\n" << std::endl;
    std::string winnerName;
    
    bool winner = false;
    while(!winner){

        std::cout << "=== Start Round == " << std::endl;
        if(!Factories->factoriesLoaded()){
            fillFactories();//this should only be called if the factories are empty and it is a new game
        }

        while(!roundComplete){

            std::string command;
        
            if(player1->getTurn()){

                bool turnComplete = false;

                while (!turnComplete && !roundComplete){
                    turnComplete = playSupportFunction(player1,player2,command);
                }
            }

            //NEEDS CHECK ROUND FUNCTION HERE

            bool turnComplete = false;

            while (!turnComplete && !roundComplete){
                turnComplete = playSupportFunction(player2,player1,command);
            }

            std::cout << std::endl;

            //NEEDS CHECK ROUND FUCTION HERE
            //NEEDS CHECK WINNER FUNCTION HERE
        }
        

        fillFactories();
        player1->makeTileMosaicUppercase();
        player2->makeTileMosaicUppercase();
        
        roundComplete = false;
        
        std::cout << "=== END OF ROUND ===" << std::endl;
        std::cout << std::endl;

        player1->scoring();
        player2->scoring();

        if(endGameConditionCheck()){
            if(player1->getScore() > player2->getScore()){
            winner = true;
            winnerName = player1->getName();
            }
            else if(player1->getScore() < player2->getScore()){
                winner = true;
                winnerName = player2->getName();
            }
        }

        //~~~~~~~~~~~~~~~~~~~~remove below once the above is done~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

        // if(player1->getScore() > player2->getScore()){
        //     winner = true;
        //     winnerName = player1->getName();
        // }
        // else if(player1->getScore() < player2->getScore()){
        //     winner = true;
        //     winnerName = player2->getName();
        // }

         //~~~~~~~~~~~~~~~~~~~~remove above condition is met~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


    }
    

    std::cout << "Congratulations!!!!!!" << std::endl;
    std::cout << "Winner is: " << winnerName << std::endl;

    std::cout << "=== GAME OVER ===" << std::endl;

}

bool GameModel::playSupportFunction(Player* player, Player* otherPlayer,std::string command){
    bool turnComplete = false;
    displayGameboard(player);
    std::cout << "> ";
    std::getline(std::cin, command);

    commandParse(command, player);
    std::cout<< std::endl;

    

    if(Factories->isEmpty()){
        roundComplete = true;
    }

    if (player->getTurn() == false){
        otherPlayer->setIsTurn(true);
        turnComplete = true;
    }
    return turnComplete;
}

void GameModel::displayGameboard(Player* player){

    // std::cout << "== Start Round ===" << std::endl;
    std::cout << "TURN FOR PLAYER:" << player->getName() <<  std::endl;
    std::cout << "Factories:" << std::endl;
    Factories->displayFactories();
    std::cout << "Mosaic for " << player->getName() << ":" << std::endl;
    player->displayGameboard();
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

    
    else if(command == "save"){
       std::string fileName = "";
       std::cout << "Enter the file name(eg: save.txt): ";
       std::cin >> fileName;
        saveGame(fileName);
    }

    else if(command == "round"){ // just a tester need to delete later

        roundComplete = true;

    }

    else if (command == "fill"){ // just a tester need to delete later

        fillFactories();
        player1->makeTileMosaicUppercase();
        player2->makeTileMosaicUppercase();
        

    }

    else if (command.substr(0,4) == "turn" || command.substr(0,4) == "TURN"){

        if ((command.substr(4,1) == " " && command.length() == 10 ) && (command.substr(6,1) == " " && command.substr(8,1) == " ")){ // checks for spaces in the right spot and proper length

            int factory = std::stoi(command.substr(5,1));
            Colour colourStr = command[7];
            int patternRow = std::stoi(command.substr(9,1));

            // player place tile function() returns bool, if false should provide error too other than the one i put below.


            bool placeTileSuccess = false;

            if(drawTileFromFactoryToPatternLine(factory,colourStr,patternRow,player)){
                placeTileSuccess = true;
            }

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

    Factories->getFactory(0).at(0)->setColour(FIRST_PLAYER);

    for (int i = 1; i < 6; i++){

        for (int j = 0; j < 4; j++){

            Tile* tilePtr = tileBag->drawTileFront();
            Factories->getFactory(i).at(j)->setColour(tilePtr->getColour()); 
            delete tilePtr; 

        }
    }
}

bool GameModel::drawTileFromFactoryToPatternLine(int factory, Colour colour, int atPatternLine, Player* player){
    bool moved = false;
    int amountOfTilesMoved = 0;
    int amountOfTilesFound = 0;
    if (factory > 0){
        for (int i = 0; i < 4; i++)
        {
            if (Factories->getFactory(factory).at(i)->getColour() == colour){
                int column = 0;
                bool setTile = false;
                while(column < atPatternLine && setTile == false){
                    if (player->getPatternLine()->getTilePatternLine()[atPatternLine-1][atPatternLine-1-column]->getColour() == NO_TILE)
                    {
                        player->getPatternLine()->getTilePatternLine()[atPatternLine-1][atPatternLine-1-column]->setColour(colour);
                        setTile = true;
                        amountOfTilesMoved++;
                    }
                    column++;
                    Factories->getFactory(factory).at(i)->setColour(NO_TILE);
                    moved = true;
                }
                amountOfTilesFound++;
            }
            else{ // THIS IS TO HELP SORT OUT THE NEW PROBLEM
                Factories->addToFactory(0, new Tile (Factories->getFactory(factory).at(i)->getColour()));// hmmmm no idea about this situation, close though.
                Factories->getFactory(factory).at(i)->setColour(NO_TILE);

            }
        }
    }
    else if (factory == 0){
        for (unsigned int i = 0; i < Factories->getFactory(0).size(); i++)
        {
            if (Factories->getFactory(0).at(i)->getColour() == colour || Factories->getFactory(0).at(i)->getColour() == FIRST_PLAYER){

                if(Factories->getFactory(0).at(i)->getColour() == FIRST_PLAYER){

                    player->getFloorLine()->addTileFront((new Tile(FIRST_PLAYER)));
                    Factories->getFactory(0).at(0)->setColour(NO_TILE);

                }
                else{

                    int column = 0;
                    bool setTile = false;
                    while(column < atPatternLine && setTile == false){
                        if (player->getPatternLine()->getTilePatternLine()[atPatternLine-1][atPatternLine-1-column]->getColour() == NO_TILE)
                        {
                            player->getPatternLine()->getTilePatternLine()[atPatternLine-1][atPatternLine-1-column]->setColour(colour);
                            setTile = true;
                            amountOfTilesMoved++;
                        }
                    
                        column++;
                        Factories->getFactory(factory).at(i)->setColour(NO_TILE);
                        moved = true;
                    }
                amountOfTilesFound++;
                }
            }
            else{ // THIS IS TO HELP SORT OUT THE NEW PROBLEM
                //Factories->addToFactory(0, new Tile (Factories->getFactory(0).at(i)->getColour()));// hmmmm no idea about this situation, close though.
                //Factories->getFactory(0).at(i)->setColour(NO_TILE);

            }
        }
    }
    else{
        moved =  false;
    }

    // if(Factories->isEmpty()){
    //     fillFactories();
    //     roundComplete = true;
    // }

    for (int i = 0; i < amountOfTilesFound - amountOfTilesMoved; i++){

        player->getFloorLine()->addTile((new Tile(colour)));                

    }

    return moved;
}

bool GameModel::endGameConditionCheck(){
    bool gameDone = false;
    if(player1->getMosaic()->hasFullRow() || player2->getMosaic()->hasFullRow()){
        gameDone = true;
    }
    return gameDone;
}

