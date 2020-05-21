#ifndef MOSAIC_H
#define MOSAIC_H

#include <array>
#include <iostream>
#include "Tile.h"

class Mosaic {
public:

    //constructor
    Mosaic();
    //destructor
    ~Mosaic();
    // gets the raw version of the mosaic 2D Array
    Tile*** getMosaic();
    // set mosaic tile to the given colour using the row and column indexes
    void setMosaicTile(int row, int column, Colour colour);
    //display mosaic
    void displayMosaic();

    //sampleidea
    void initMosaicPattern();
    // checks if the mosaic has atleast one full row(used to check winning condition)
    bool hasFullRow();

    
private:

    Tile** mosaicArray[5];
    
};

#endif //MOSAIC_H