#ifndef TILE_H
#define TILE_H

#include "TileCode.h"

class Tile {
public:
    Tile(Colour colour);
    Tile(Tile& other);
    ~Tile();
    Colour getColour();
    void setColour(Colour colour);
    bool Tile::matchTile(Tile *t);
    
private:
    Colour colour;
};

#endif // TILE_H