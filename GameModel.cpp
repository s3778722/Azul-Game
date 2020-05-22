#include "GameModel.h"

GameModel::GameModel(std::string player1Name, std::string player2Name){

    player1 = new Player(player1Name);
    player1->setIsTurn(true);
    player2 = new Player(player2Name);
    Factories = new FactoryTable();
    tileBag = new TileBag();
    boxLid = new BoxLid();
    //This boolean isn't neccessary but the game ended up requiring this being
    //a value accessible from multiple areas. So here we are.
    roundComplete = false; 
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
    delete player1;
    delete player2;
    delete Factories;
    delete tileBag;
    delete boxLid;
}

void GameModel::play(){
    
    std::cin.ignore();
    std::cout << "Let's Play!\n" << std::endl;
    std::string winnerName;

    if(!Factories->factoriesLoaded()){
        fillFactories();//this should only be called if the factories are empty and it is a new game
    }
    
    bool winner = false;
    while(!winner && !quit && !std::cin.eof()){

        std::cout << "=== Start Round == " << std::endl;
        
        if(tileBag->bagSize() == 0){ // fills up the tile bag if it has run out of tiles
            for(int i=boxLid->size()-1;i>0;i--){
                tileBag->addTile(boxLid->getBoxLid().at(i));
                boxLid->getBoxLid().pop_back();
            }
        }
        //This loop goes till theres a quit, eof or the round ends.
        while(!roundComplete && !quit && !std::cin.eof()){
            std::string command;
            if(player1->getTurn()){
                bool turnComplete = false;
                while ((!turnComplete && !roundComplete) && !quit && !std::cin.eof()){
                    turnComplete = playSupportFunction(player1,player2,command);
                }
            }
            bool turnComplete = false;

            while ((!turnComplete && !roundComplete) && !quit && !std::cin.eof()){
                turnComplete = playSupportFunction(player2,player1,command);
            }

            std::cout << std::endl;
        }
        // if the round ends this executes
        if(roundComplete){

            // Resets factories
            fillFactories();
            // This is how we move the tiles over, we make them uppercase
            player1->makeTileMosaicUppercase();
            player2->makeTileMosaicUppercase();
            // Makes the round false so it is able start again after this if statement
            roundComplete = false;
            std::cout << "=== END OF ROUND ===" << std::endl;
            std::cout << std::endl;

            //scores the players and creates a LinkeList of "discarded " tiles to go to the boxlid. 
            LinkedList* goesToBoxLidPlayer1 = player1->scoring();
            LinkedList* goesToBoxLidPlayer2 = player2->scoring();
            
            for(int i=0;i<goesToBoxLidPlayer1->getSize();i++){
                boxLid->addTile(goesToBoxLidPlayer1->removeFront());
            }

            for(int i=0;i<goesToBoxLidPlayer2->getSize();i++){
                boxLid->addTile(goesToBoxLidPlayer2->removeFront());
            }
            // checks if the game ended and sets whoever won, if there wasn't a draw.
            // also sets the game to finished if a winner is crowned.
            if(endGameConditionCheck()){
                if(player1->getScore() > player2->getScore()){
                winner = true;
                winnerName = player1->getName();
                }
                else if(player1->getScore() < player2->getScore()){
                    winner = true;
                    winnerName = player2->getName();
                }
                else if(player1->getScore() == player2->getScore()){
                    winner = false;
                }
            }
        }
    }
    if(!quit && winner){

        std::cout << "Congratulations!!!!!!" << std::endl;
        std::cout << "Winner is: " << winnerName << std::endl;
        std::cout << "=== GAME OVER ===" << std::endl;
    }
    else if(!quit && !winner){
        std::cout << "The game is a draw...... Better luck next time!!!" << std::endl;
        std::cout << "=== GAME OVER ===" << std::endl;
    }

    else{
        std::cout << "Quit Game Successfully" << std::endl;
    }
}
bool GameModel::playSupportFunction(Player* player, Player* otherPlayer,std::string command){
    // A helper method to take a command, and will set the other players turn if turn successful
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
// Displays the gameboard in its proper format for the player given

    std::cout << "TURN FOR PLAYER:" << player->getName() <<  std::endl;
    std::cout << "SCORE: " << player->getScore() << std::endl;
    std::cout << "Factories:" << std::endl;
    Factories->displayFactories();
    std::cout << "Mosaic for " << player->getName() << ":" << std::endl;
    player->displayGameboard();
}

void GameModel::saveGame(std::string saveFileName){
//Saves the game according to the proper format we decided on
    std::ofstream saveFile(saveFileName);
    saveFile.clear();//not sure if this is needed but i'll put here
    
    for (int i = 0; i < Factories->getSize(); i++){ //factories
        for(unsigned int j=0; j<Factories->getFactory(i).size(); j++){
            saveFile << Factories->getTable().at(i).at(j)->getColour();
            if(j < Factories->getFactory(i).size()-1){ // -1 due to indexing
                saveFile << " ";
            }
        }
        saveFile << std::endl;
    }
    
    saveFile << std::endl;
    for(int i=0;i<tileBag->bagSize();i++){ // tilebag
        saveFile << tileBag->getTile(i)->getColour();
        if(i < tileBag->bagSize()-1){ // -1 due to indexing
                saveFile << " ";
        }
    }
    
    if(boxLid->size() == 0){
        saveFile << std::endl;
    }

    else{
        for(int i=0; i<boxLid->size();i++){ //boxlid
            saveFile << boxLid->getBoxLid().at(i);
            if(i < boxLid->size()-1){ // -1 due to indexing
                    saveFile << " ";
            }
        }
    }
    saveFile << std::endl;
    saveFile << std::endl;
    //Saves the data from player 1, then player 2
    savePlayerData(player1,saveFile);
    saveFile << std::endl;
    savePlayerData(player2,saveFile);
    saveFile.close();
    std::cout << "Game successfully saved to ’" << saveFileName << "’" << std::endl;
}

void GameModel::savePlayerData(Player* player, std::ofstream& saveFile){
    //Goes through each piece of data and saves it accordingly
    saveFile << player->getName() << std::endl;
    saveFile << player->getTurn() << std::endl;
    saveFile << player->getScore() << std::endl << std::endl;

    Tile*** mosaicGrid = player->getMosaic()->getMosaic();
    Tile*** patternLineGrid = player->getPatternLine()->getTilePatternLine();
    LinkedList* floorLine = player->getFloorLine()->getFloorLine();

    for(int i=0;i<5;i++){ // pattern line
        for(int j=0; j<i+1; j++){
            saveFile << patternLineGrid[i][j]->getColour();
        }
        saveFile << std::endl;
    }

    saveFile << std::endl;

    for(int i=0;i<5;i++){ // mosaic/board/wall
        for(int j=0; j<5; j++){
            if(islower(mosaicGrid[i][j]->getColour())){
                Colour colour =mosaicGrid[i][j]->getColour();
                mosaicGrid[i][j]->setColour(NO_TILE);
                saveFile << mosaicGrid[i][j]->getColour();
                mosaicGrid[i][j]->setColour(colour);
            }
            else{
                saveFile << mosaicGrid[i][j]->getColour();
            }
            saveFile << " ";
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

void GameModel::commandParse(std::string command, Player* player){ //This method is the basis behind the whole input system.

    // The idea here is it checks for specific substrings to perform the action wanted.
    // If it doesn't recieve what it wants it will show a default response. Help is shown within the
    // Help command, though it would be better to have specific reponses for each problem. It requires
    // alot more to get that done.


    if (command.substr(0,4) == "help" || command.substr(0,4) == "HELP"){
        if (command.length() == 4){
            std::cout << "Please enter the factory number, tile character chosen, and pattern line to take it to." << std::endl;
            std::cout << "For list of commands type: help commands, for help with a speciic command type help <command>. " << std::endl;
        }
        
        else if (command.length() == 13){
            if (command.substr(5,8) == "commands" || command.substr(5,8) == "COMMANDS"){
            std::cout << "valid commands include: turn, quit, save, help";     
            }
            else {
                std::cout << "thats not a valid help command";
            }
        }

        // sub commands for help, extra arguements for help in other areas.
        else if (command.length() == 9){
            if (command.substr(5,4) == "turn" || command.substr(5,4) == "TURN" ){
                std::cout << "Turn format is as follows: turn <factory number> <colour of tile> <patternline to move to>" << std::endl;
                std::cout << "If you have to place directly into the broken line, just move into line 6." << std::endl;
            }

            else if(command.substr(5,4) == "save" || command.substr(5,4) == "SAVE" ){
                std::cout << "This will save the game in its current state." << std::endl;
                std::cout << "just type whatever you want to call the save and add extention .txt to the end." << std::endl;
            }

            else if(command.substr(5,4) == "help" || command.substr(5,4) == "HELP" ){
                std::cout << "You're better than that!" << std::endl;
                std::cout << "help yourself lol." << std::endl;
            }

            else if(command.substr(5,4) == "quit" || command.substr(5,4) == "QUIT" ){
                std::cout << "Quits the game right then safely." << std::endl;
                std::cout << "Will ask if you would like to save." << std::endl;
            }
            else {
                std::cout << "thats not a valid help command";
            }
        }
        else {
            std::cout << "thats not a valid help command";
        }
    }
    //Save, and Quit then save, straight forward as it uses other methods previously explained.
    else if(command == "save" || command == "SAVE"){
       std::string fileName = "";
       std::cout << "Enter the file name(eg: save.txt): ";
       std::cin >> fileName;
        saveGame(fileName);
    }

    else if(command == "quit" || command == "QUIT"){
        std::string choice;
        while (choice != "Y" && choice != "N"){
            std::cout << "WOULD YOU LIKE TO SAVE? Y/N: ";
            std::cin >> choice;
                if (choice == "Y"){
                    std::string fileName = "";
                    std::cout << "Enter the file name(eg: save.txt): ";
                    std::cin >> fileName;
                    saveGame(fileName);
                    std::cout << "File saved and quitting" << std::endl;
                }
                else if (choice != "N"){
                    std::cout << "Please enter either Y or N!" << std::endl;
                }
        }
    quit = true;
    }

    else if (command.substr(0,4) == "turn" || command.substr(0,4) == "TURN"){
        if ((command.substr(4,1) == " " && command.length() == 10 ) && (command.substr(6,1) == " " && command.substr(8,1) == " ")){

    // command will check for a specific size and expects gaps between arguments, if it doesn't get it,
    // it will complain and eventually will run again it then parses the arguments within the gaps below
            int factory;
            Colour colourStr;
            int patternRow;
            bool format = true;

            //These try catch blocks were the easiest way to handle this issue if the format was incorrect,
            //invalid_arguement exception is caught if the format was wrong, so we make you input again if wrong.
            try {
                factory = std::stoi(command.substr(5,1));
            }
            catch(std::invalid_argument& e){
                std::cout << "Please enter a number for factory only" << std::endl;
                format = false;
            }

            colourStr = command[7];

            if (format){
                try {
                    patternRow = std::stoi(command.substr(9,1));
                }
                catch(std::invalid_argument& e){
                    std::cout << "Please enter a number for patternline only" << std::endl;
                    format = false;
                }
            }
            // Makes sure the pattern row is an appropiate value when passing it on. 
            if (format){
                if(patternRow > 6){
                    format = false;
                }
            }
            
            bool placeTileSuccess = false;
            // Would have been smarter to not use this boolean but our drawTile function to check
            if(format == true){
                if(drawTileFromFactoryToPatternLine(factory,colourStr,patternRow,player)){
                    placeTileSuccess = true;
                }
            }
            if(placeTileSuccess){ 
                player->setIsTurn(false); // goes to the next player now
            }
            else{
                std::cout << "Tile Couldn't be placed." <<  std::endl;
            }
        }
        else{
            std::cout << "please type a valid command, if you need help type: help.";
        }
    }
}

//This fills the factories drawing from the bag and adds the first player tile to factory 0.
void GameModel::fillFactories(){
    if(Factories->getFactory(0).size() == 0){
        Factories->getFactory(0).push_back(new Tile(FIRST_PLAYER));
    }
    else{
        Factories->getFactory(0).at(0)->setColour(FIRST_PLAYER);
    }
    // Loops and adds all tiles for factories 1-5
    for (int i = 1; i < 6; i++){
        for (int j = 0; j < 4; j++){
            Tile* tilePtr = tileBag->drawTileFront();
            Factories->getFactory(i).at(j)->setColour(tilePtr->getColour()); 
            delete tilePtr; 
        }
    }
}

bool GameModel::drawTileFromFactoryToPatternLine(int factory, Colour colour, int atPatternLine, Player* player){
    //The main heart of the game rules and logic
    bool moved = false;
    // if moved, then it was a successful turn, if not. It failed.
    int amountOfTilesMoved = 0;
    //the amount of tiles found of the colour in factory that successfully moved to the patternline
    int amountOfTilesFound = 0;
    // The amount of tiles found of the colour in the factory

    if(atPatternLine == 6){
        // This will add the factory tiles of the colour to the brokenline instead of the patternlines.
        // this applies for factories that aren't 0.
        if (factory > 0 && factory < 6){
            for (int i = 0; i < 4; i++)
            {
                if (Factories->getFactory(factory).at(i)->getColour() == colour){
                    player->getFloorLine()->addTile((new Tile(colour)));
                    Factories->getFactory(factory).at(i)->setColour(NO_TILE);
                    amountOfTilesFound++;
                    amountOfTilesMoved++;
                    moved = true;                
                }
                else{ // Rest of the tiles are sent to factory 0
                    Factories->addToFactory(0, new Tile (Factories->getFactory(factory).at(i)->getColour()));// hmmmm no idea about this situation, close though.
                    Factories->getFactory(factory).at(i)->setColour(NO_TILE);
                    // Clears the factory afterwards

                }
            }
        }
        //now applying to factory 0
        //same idea but accounts for the first player tile also
        else if (factory == 0){
            for (unsigned int i = 0; i < Factories->getFactory(0).size(); i++)
            {
                if (Factories->getFactory(0).at(i)->getColour() == colour || Factories->getFactory(0).at(i)->getColour() == FIRST_PLAYER){
                    if(Factories->getFactory(0).at(i)->getColour() == FIRST_PLAYER){
                        player->getFloorLine()->addTileFront((new Tile(FIRST_PLAYER)));
                        Factories->getFactory(0).at(0)->setColour(NO_TILE);
                        moved = true;
                    }
                    else{
                        player->getFloorLine()->addTile((new Tile(colour)));
                        Factories->getFactory(0).at(i)->setColour(NO_TILE);
                        moved = true;
                    }
                        amountOfTilesFound++;
                        amountOfTilesMoved++;
                }
            }
        }
    }
    
    
    else if (player->getPatternLine()->getTilePatternLine()[atPatternLine-1][atPatternLine-1]->getColour() == NO_TILE || player->getPatternLine()->getTilePatternLine()[atPatternLine-1][atPatternLine-1]->getColour() == colour){
    //Apologies for the extremely long if statement, this checks if the pattern line is free or/and has the correct colour of the incoming tile. or it wont let it place
        if ((factory > 0 && factory < 6) && !player->getMosaic()->checkRowForTile(atPatternLine,colour)){
        // applies to factories 1-5 only and checks if there is a tile already in the mosiac in this row. or it wont let it place
            for (int i = 0; i < 4; i++){
                //loops through the factory, making decisions tile by tile.
                if (Factories->getFactory(factory).at(i)->getColour() == colour){
                    int column = 0;
                    bool setTile = false;
                    while(column < atPatternLine && setTile == false){
                        if (player->getPatternLine()->getTilePatternLine()[atPatternLine-1][atPatternLine-1-column]->getColour() == NO_TILE){   // Again, -1 due to indexing
                            player->getPatternLine()->getTilePatternLine()[atPatternLine-1][atPatternLine-1-column]->setColour(colour);         // The - column allows it to store from the right to left
                            setTile = true;
                            amountOfTilesMoved++;
                        }
                        column++;
                        Factories->getFactory(factory).at(i)->setColour(NO_TILE);
                        //Clears factory
                        moved = true;
                    }
                    amountOfTilesFound++;
                }
                else{ 
                    Factories->addToFactory(0, new Tile (Factories->getFactory(factory).at(i)->getColour()));
                    Factories->getFactory(factory).at(i)->setColour(NO_TILE);
                    //Adds tiles to factory 0 and clears the factory they came from.
                }
            }
        }
        else if (factory == 0 && !player->getMosaic()->checkRowForTile(atPatternLine,colour)){
            //applies to factory 0 only as it has different logic, the checks are the same at the beginning, although it deals with the first
            //player token and moves it if it needs to, and doesn't move tiles that are left over from factory 0
            //it leaves them there
            for (unsigned int i = 0; i < Factories->getFactory(0).size(); i++){
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
            }
        }
        else{
            moved =  false;
        }
    }
    // used to fill the broken line, if the amount of tiles found are more than the amount moved
    // it will overflow into the broken line and be placed in here. 

    for (int i = 0; i < amountOfTilesFound - amountOfTilesMoved; i++){

        player->getFloorLine()->addTile((new Tile(colour)));                

    }
    return moved;
}


bool GameModel::endGameConditionCheck(){
//checks if the game is over by seeing if the row is full.
    bool gameDone = false;
    if(player1->getMosaic()->hasFullRow() || player2->getMosaic()->hasFullRow()){
        gameDone = true;
    }
    return gameDone;
}