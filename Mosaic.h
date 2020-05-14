#ifndef MOSAIC_H
#define MOSAIC_H

#include <array>
#include <iostream>
#include "Tile.h"

class Mosaic {
public:

    Mosaic();
    ~Mosaic();
    Tile*** getMosaic();
    void setMosaic(Tile** array);
    void displayMosaic();

    void mosaicPattern();//sampleidea
    bool hasFullRow();

    
private:

    Tile** mosaicArray[5];

    // std::array<std::array<Tile*,5>,5> mosaicArray;
    
};

#endif //MOSAIC_H