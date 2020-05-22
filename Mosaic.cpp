#include "Mosaic.h"

Mosaic::Mosaic(){
    initMosaicPattern();
}

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

//displays the mosiac, this is controlled by the player class now but is kept in due to it may be
//needed later on in enhancements.

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

//creates the mosiac according to the games pattern, used to guide the tile to the right position on the mosaic.
void Mosaic::initMosaicPattern(){
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
