#include "FloorLine.h"

FloorLine::FloorLine(){
    floorLine = new LinkedList();
}

FloorLine::~FloorLine(){
    delete floorLine;
}

void FloorLine::addTile(Tile* tile){
    floorLine->addBack(tile);
}

void FloorLine::addTileFront(Tile* tile){
    floorLine->addFront(tile);
}

Tile* FloorLine::removeTile(){
    Tile* returnTile = nullptr;
    if(floorLine->getSize() != 0){
        returnTile = floorLine->getTile(0); // this is thinking that the linked list goes from 0 onwards in indexing
        floorLine->removeFront();
    }
    return returnTile;
}

int FloorLine::getNegativePoints(){ // think of a way to make this better.... nicer
    // for(int i=0;i<floorLine->getSize();i++){
    //     floorLine->getTile(i);
    // }
    int negativePoints = 0;
    int size = floorLine->getSize();
    if(size == 1){
        negativePoints = -1;
    }
    else if(size == 2){
        negativePoints = -2;
    }
    else if(size == 3){
        negativePoints = -4;
    }
    else if(size == 4){
        negativePoints = -6;
    }
    else if(size == 5){
        negativePoints = -9;
    }
    else if(size == 6){
        negativePoints = -12;
    }
    else{
        negativePoints = 0;
    }

    for(int i=0;i<floorLine->getSize();i++){
        delete floorLine->getTile(i);
    }

    return negativePoints;
}

void FloorLine::displayFloorLine(){
    int size = floorLine->getSize();
    if(size != 0){
        for(int i=0; i<size; i++){
            std::cout << floorLine->getTile(i)->getColour() << " ";
        }
        std::cout << std::endl;
    }
    else{
        std::cout << std::endl;
    }
}

LinkedList* FloorLine::getFloorLine(){
    return floorLine;
}