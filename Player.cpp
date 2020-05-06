#include "Player.h"

Player::Player(std::string name){

    this->name = name;

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