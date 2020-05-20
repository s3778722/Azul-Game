#ifndef FLOORLINE_H
#define FLOORLINE_H

#include "LinkedList.h"
#include "iostream"

class FloorLine {
public:
    FloorLine();
    ~FloorLine();

    void addTile(Tile* tile);
    Tile* removeTile(); // removes the tile from the front
    int getNegativePoints();
    void displayFloorLine();
    LinkedList* getFloorLine();
    void addTileFront(Tile* tile);
    LinkedList* getToBoxLid();
    
private:
    LinkedList* floorLine;
    LinkedList* toBoxLid;
    
};

#endif // FLOORLINE_H