#include "FloorLine.h"

FloorLine::FloorLine(){
    floorLine = new LinkedList();
    toBoxLid = new LinkedList();
}

FloorLine::~FloorLine(){
    delete floorLine;
    delete toBoxLid;
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

int FloorLine::getNegativePoints(){

    int negativePoints = 0;
    int size = floorLine->getSize();
    if (size == 0){
        negativePoints = 0;
    }
    else if(size == 1){
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
        negativePoints = -8;
    }
    else if(size == 6){
        negativePoints = -11;
    }
    else if(size == 7){
        negativePoints = -14;
    }
    else{
        negativePoints = (-14-((size -7)*3));
    }

    if(floorLine->getSize() > 0){
        if(floorLine->getTile(0)->getColour() == FIRST_PLAYER){
            floorLine->removeFront();
        }
        int removeSize = floorLine->getSize()+1;
        for(int i=0;i < removeSize;i++){
            toBoxLid->addBack(floorLine->removeFront());
        }
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

LinkedList* FloorLine::getToBoxLid(){
    return toBoxLid;
}