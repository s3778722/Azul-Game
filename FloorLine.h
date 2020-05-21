#ifndef FLOORLINE_H
#define FLOORLINE_H

#include "LinkedList.h"
#include "iostream"

class FloorLine {
public:
    //constructor
    FloorLine();
    //destructor
    ~FloorLine();

    // adds the tile to the back of the list
    void addTile(Tile* tile);
    // removes the tile from the front
    Tile* removeTile(); 
    //gets the negative points of the floorline
    int getNegativePoints();
    // displays the floor line
    void displayFloorLine();
    // get the raw floor line linked list
    LinkedList* getFloorLine();
    // adds tile to the front of the floorline
    void addTileFront(Tile* tile);
    // get the tiles that should go into the boxlid as a linked list
    LinkedList* getToBoxLid();
    
private:
    LinkedList* floorLine;
    LinkedList* toBoxLid;
    
};

#endif // FLOORLINE_H