#include "Player.h"

Player::Player(std::string name){

    this->name = name;
    mosiac = new Mosiac();
    

    this->playerFloorLine = new FloorLine();

    playerFloorLine->addTile(new Tile(YELLOW));
    playerFloorLine->addTile(new Tile(BLACK));

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

    for (int i = 0; i < 5; i++){

    std::cout << i <<"1:";

        for (int j = 0; j < 5; j++){
            std::cout << "|| " << mosiac->getMosiac().at(i).at(j)->getColour();
        }
        std::cout << std::endl;        
    }

    std::cout << std::endl;

    //the floorline stuff
    std::cout << "Broken:";
    playerFloorLine->displayFloorLine();
    

}