#include "Player.h"

Player::Player(std::string name){

    this->name = name;
    this->mosaic = new Mosaic();
    this->playerFloorLine = new FloorLine();
    this->playerPatternLine = new PatternLine();

}

Player::~Player(){
    delete mosaic;
    delete playerFloorLine;
    delete playerPatternLine;
    for(int i=0;i<5;i++){
        delete[] scoringBoard[i];
    }
    delete[] scoringBoard;
    delete[] colourTiles;
}

Player::Player(std::string name, int score, bool isTurn, Mosaic* mosaicLoad, FloorLine* FloorLineLoad, PatternLine* patternLineLoad){

    this->name = name;
    this->score = score;
    this->isTurn = isTurn;
    this->mosaic = mosaicLoad;
    this->playerFloorLine = FloorLineLoad;
    this->playerPatternLine = patternLineLoad;

}

int Player::getScore(){

    return this->score;

}

void Player::addPoints(int points){
    this->score += points;
}


std::string Player::getName(){

    return this->name;
}

bool Player::getTurn(){

    return this->isTurn;
}

void Player::setIsTurn(bool isTurn){

    this->isTurn = isTurn;
    
}

void Player::displayGameboard(){

    Tile*** patternLineGrid = playerPatternLine->getTilePatternLine();
    Tile*** mosaicGrid = mosaic->getMosaic(); //use this to access the mosaic and print the stuff

    for(int i=0;i<5;i++){
        std::cout << i+1 << ": ";
        for(int s=0;s<4-i;s++){
            std::cout << "  ";
        }
        for(int j=0; j<i+1; j++){
            std::cout << patternLineGrid[i][j]->getColour()<< " ";
        }
        std::cout << "|| ";
        //mosaic stuff here
        for(int j=0; j<5; j++){

            if (std::isupper(mosaicGrid[i][j]->getColour())){
                std::cout << mosaicGrid[i][j]->getColour();
            }

            else{
                std::cout << '.';
            }

            std::cout << " ";
        }
            
        std::cout << std::endl;
    }

    // std::cout << std::endl;

    //the floorline stuff
    std::cout << "Broken:";
    playerFloorLine->displayFloorLine();
    

}

FloorLine* Player::getFloorLine(){
    return playerFloorLine;
}

PatternLine* Player::getPatternLine(){
    return playerPatternLine;
}

Mosaic* Player::getMosaic(){
    return mosaic;
}

//It will make the tile on mosaic to display the Pattern if the patternline row is full.
std::vector<Tile*> Player::makeTileMosaicUppercase(){
    std::vector<Tile*> tileVector;
    for (int i = 0; i < 5; i++)
    {
        if (playerPatternLine->isPatternLineFull(i)){
            Colour colour = playerPatternLine->getTilePatternLine()[i][0]->getColour();
            for (int j = 0; j < 5; j++){
                if (tolower(colour) == mosaic->getMosaic()[i][j]->getColour())
                {
                    mosaic->getMosaic()[i][j]->setColour(colour);
                    this->getScoreBoard()[i][j] = 'X';
                    Tile* tile = playerPatternLine->getTilePatternLine()[i][0];
                    tileVector.push_back(tile);
                    for(int k = 0;k<i+1;k++){
                        playerPatternLine->getTilePatternLine()[i][k]->setColour(NO_TILE);
                    }
                }
           }
        }
    }
    return tileVector;
}

char** Player::getScoreBoard(){
    return scoringBoard;
}

void Player::scoring()
{
    scoringBoard = new char*[5];
    colourTiles = new bool[5];

    for (int i = 0; i < 5; i++){
        scoringBoard[i] = new char[5];
    }

    for(int x=0; x < 5; x++)
    {
        for(int y = 0; y < 5; y++)
        {
            this->scoringBoard[x][y] = NO_TILE;
        }
    }

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            //if(scoringBoard[i][j] == toupper(mosaic->getMosaic()[i][j]->getColour())){
            if(scoringBoard[i][j] == 'X'){
                //Uppercase 'X' to represent that is Uppercase on Mosaic
                checkRow.push_back(i);
                checkColumn.push_back(j);
            }
        }
    }

    checkingRow = true;
    checkingColumn = true;

    for(unsigned int i = 0; i < checkRow.size(); i++)
    {
        bool rowCounted = false;
        bool columnCounted = false;

        scoringBoard[checkRow[i]][checkColumn[i]] = 'x'; 
        //mark it as 'x' to represent that it is checked
        
        //South
        for(int j = ((checkColumn[i]) + 1); j < 5; j++)
        {
            if(scoringBoard[checkRow[i]][j] == 'x'){
                score++;  
                if(j == ((checkColumn[i])+1)){
                    rowCounted = true;
                    score++;
                }
            }else{
                j = 5;
                checkingRow = false;
            }
        }
        //North
        for(int j = ((checkColumn[i])-1); j >= 0; j--)
        {
            if(scoringBoard[checkRow[i]][j] == 'x'){
               score++;  
               if(rowCounted == false){
                   rowCounted = true;
                   score++;
                }
            }else{
                j = 0;
                checkingRow = false;
            }
        }
        //East
        for(int j = ((checkRow[i])+1); j <  5; j++)
        {
            if(scoringBoard[j][checkColumn[i]] == 'x'){
               score++;
               if(j == checkRow[i]+1){
                   columnCounted = true;
                   score++;
                }
            }else{
               j = 5;
               checkingColumn = false;
            }
        }
        //West
        for(int j = ((checkRow[i]-1)); j >= 0; j--)
        {
            if(scoringBoard[j][checkColumn[i]] == 'x'){
               score++;
               if(columnCounted == false){
                   columnCounted = true;
                   score++;
                }
            }else{
               j = 0;
               checkingColumn = false;
            }
        }
        if(checkingRow == true)
        {
            score+=2;
        }
        if(checkingColumn == true)
        {
            score+=7;
        }
        else if (rowCounted == false && columnCounted == false)
        {
            columnCounted = true;
            score++;
        }
    }
    //checkBrokenTiles();
    countColours();
    scoreColours();
}

void Player::checkBrokenTiles(){
    for (int i = 0; i <= playerFloorLine->getNegativePoints(); i++)
    {
        if(playerFloorLine->getFloorLine()->getTile(i) != nullptr)
        {
            if(i >= 0 && i < 2){
                score--;
            }
            if(i >= 2 && i < 5){
                score -= 2;
            }
            else {
                score -= 3;
            }
        }
        else
        {
            i = playerFloorLine->getNegativePoints()+1;
        }
    }
}

void Player::countColours(){
    for(int i = 0; i <  5; i++)
    {
        for(int j = 0; j <  5; j++)
        {
            if(mosaic->getMosaic()[i][j]->getColour() == RED){
                redCounter++;
            }
            if(mosaic->getMosaic()[i][j]->getColour() == LIGHT_BLUE){
                lightblueCounter++;
            }
            if(mosaic->getMosaic()[i][j]->getColour() == DARK_BLUE){
                blueCounter++;
            }
            if(mosaic->getMosaic()[i][j]->getColour() == YELLOW){
                yellowCounter++;
            }
            if(mosaic->getMosaic()[i][j]->getColour() == BLACK){
                blackCounter++;
            }
        }
    }
}

void Player::scoreColours(){
    if(redCounter == 5 && colourTiles[0] == false) 
    {   
        score += 10; 
        colourTiles[0] = true;
    }
    if(lightblueCounter == 5 && colourTiles[1] == false) 
    {   
        score += 10; 
        colourTiles[1] = true;
    }
    if(blueCounter == 5 && colourTiles[2] == false)
    {   
        score += 10; 
        colourTiles[2] = true;
    }
    if(yellowCounter == 5 && colourTiles[3] == false)
    {   
        score += 10; 
        colourTiles[3] = true;
    }
    if(blackCounter == 5 && colourTiles[4] == false)
    {   
        score += 10; 
        colourTiles[4] = true;
    }
}

    