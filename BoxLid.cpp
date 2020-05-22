#include "BoxLid.h"

BoxLid::BoxLid():
    boxLidVector()
{}

BoxLid::~BoxLid(){

}

int BoxLid::size(){
    return (int)boxLidVector.size();
}

void BoxLid::addTile(Tile* tile){
    boxLidVector.push_back(tile);
}

void BoxLid::clearAll(){
    boxLidVector.clear();
}

std::vector<Tile*> BoxLid::getBoxLid(){
    return boxLidVector;
}

std::string BoxLid::toString(){
    return "a";
}