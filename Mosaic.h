#ifndef MOSAIC_H
#define MOSAIC_H

#include <array>
#include <iostream>
#include "Tile.h"

class Mosaic {
public:

    Mosaic();
    // Mosaic(Tile** mosaicArrayLoad);
    ~Mosaic();
    Tile*** getMosaic();
    void setMosaicTile(int row, int column, Colour colour);
    void displayMosaic();

    void initMosaicPattern();//sampleidea
    bool hasFullRow();

    
private:

    Tile** mosaicArray[5];

    // std::array<std::array<Tile*,5>,5> mosaicArray;
    
};

#endif //MOSAIC_H