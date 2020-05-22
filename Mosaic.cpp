#include "Mosaic.h"

Mosaic::Mosaic(){
    initMosaicPattern();
    //displayMosaic();
}

// Mosaic::Mosaic(Tile** mosaicArrayLoad){
//     *this->mosaicArray = mosaicArrayLoad;
// }

Mosaic::~Mosaic(){
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            delete mosaicArray[i][j];
        }
    }

}

Tile*** Mosaic::getMosaic(){
    return mosaicArray;
}

void Mosaic::setMosaicTile(int row, int column, Colour colour){
    mosaicArray[row][column]->setColour(colour);
}

//tested with Uppercase letter to be displayed and it is working
void Mosaic::displayMosaic(){
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if(islower(mosaicArray[i][j]->getColour()))
            {
                mosaicArray[i][j]->setColour(NO_TILE);
            }
        }
    }
}

void Mosaic::initMosaicPattern(){
    //Tested and it is working
    std::string pattern = "byrullbyruulbyrrulbyyrulb";
    int counter = 0;
    for (int i = 0; i < 5; i++){
        this->mosaicArray[i] = new Tile*[5];
        for(int j = 0; j<5; j++){
            this->mosaicArray[i][j] = new Tile(pattern[counter]);
            counter++;
        }
    }
}

/**
 * Set full as false
 *  For each row, count = 0
 *      For each column if mosaicarray is uppercase, count+1
 *          if count is 4
 *              set full as true;
 *  Return full
 *  END
 **/
bool Mosaic::hasFullRow(){
    bool full = false;
    for(int row = 0; row < 5; row++){
        int count = 0;
        for(int column = 0; column<5; column++){
            if(isupper(mosaicArray[row][column]->getColour())){
                count++;
            }
            if (count == 4){
                full = true;
            }
        }
    }
    return full;
}

bool Mosaic::checkRowForTile(int row, Colour colourToCheck){
    bool found = false;
    for(int column = 0; column<5; column++){
        if(mosaicArray[row-1][column]->getColour() == colourToCheck){
            found = true;
        }
    }
    return found;
}
