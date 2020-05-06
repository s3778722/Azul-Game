#include "BoxLid.h"

BoxLid::BoxLid():
    boxLidVector()
{

}

BoxLid::~BoxLid(){

}

int BoxLid::size(){
    return boxLidVector.size();
}

void BoxLid::addTile(Tile* tile){
    boxLidVector.push_back(tile);
}

void BoxLid::clearAll(){
    boxLidVector.clear();
}

std::string BoxLid::toString(){

    return "f off";

}