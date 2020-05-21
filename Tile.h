#ifndef TILE_H
#define TILE_H

#include "TileCode.h"

class Tile {
public:
    // constructor
    Tile();
    // overloaded constructor
    Tile(Colour colour);
    // copy constructor
    Tile(Tile& other);
    // destructor
    ~Tile();
    // get tile colour
    Colour getColour();
    // set tile colour
    void setColour(Colour colour);
    // check if the tile colour matches to another tile
    bool matchTile(Tile *t);
    
private:
    Colour colour;
};

#endif // TILE_H