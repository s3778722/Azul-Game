#ifndef FLOORLINE_H
#define FLOORLINE_H

#include "LinkedList.h"

class FloorLine {
public:
    FloorLine();
    ~FloorLine();

    void addTile(Tile* tile);
    Tile* removeTile(); // removes the tile from the front
    int getNegativePoints();
    
private:
    LinkedList* floorLine;
    
};

#endif // FLOORLINE_H