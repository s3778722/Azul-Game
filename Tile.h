#ifndef TILE_H
#define TILE_H
#include <iostream>
typedef char Colour;

class Tile {
public:
    Tile(Colour colour);
    Colour getColour();
    void setColour(Colour colour);
    
private:
    Colour colour;
};

#endif // TILE_H