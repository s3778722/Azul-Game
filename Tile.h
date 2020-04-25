#ifndef TILE_H
#define TILE_H

typedef char Colour;

class Tile {
public:
    Tile(Colour colour);
    ~Tile();
    Colour getColour();
    void setColour(Colour colour);
    
private:
    Colour colour;
};

#endif // TILE_H