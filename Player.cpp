#include "Player.h"

Player::Player(std::string name){

    this->name = name;
    this->mosaic = new Mosaic();
    this->playerFloorLine = new FloorLine();
    this->playerPatternLine = new PatternLine();

    playerFloorLine->addTile(new Tile(YELLOW));//remove later
    playerFloorLine->addTile(new Tile(BLACK));//remove later

}

Player::~Player(){
    //TODO
}

Player::Player(std::string name, int score, bool isTurn){

    this->name = name;
    this->score = score;
    this->isTurn = isTurn;

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
            std::cout << mosaicGrid[i][j]->getColour()<< " ";
        }
        std::cout << std::endl;
    }

    // std::cout << std::endl;

    //the floorline stuff
    std::cout << "Broken:";
    playerFloorLine->displayFloorLine();
    

}