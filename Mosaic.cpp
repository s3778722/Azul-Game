#include "Mosaic.h"

Mosaic::Mosaic(){
    /*
    for(int j=0; j<5; j++){
        this->mosaicArray[j] = new Tile*[5];
        for(int i=0;i<5; i++){
            this->mosaicArray[j][i] = new Tile(); 
        }
    }*/
    initMosaicPattern();
    //displayMosaic();
}

// Mosaic::Mosaic(Tile** mosaicArrayLoad){
//     *this->mosaicArray = mosaicArrayLoad;
// }

Mosaic::~Mosaic(){
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
        // delete[] tilePatternArray[i];
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

//sample idea
void Mosaic::initMosaicPattern(){
    /*
    for(int i = 0; i < 5; i++){
        this->mosaicArray[i][i] = new Tile('b');
        this->mosaicArray[i][i+1] = new Tile('y');
        this->mosaicArray[i][i+2] = new Tile('r');
        this->mosaicArray[i][i+3] = new Tile('u');
        this->mosaicArray[i][i+4] = new Tile('l');
        this->mosaicArray[i][i-1] = new Tile('l');
        this->mosaicArray[i][i-2] = new Tile('u');
        this->mosaicArray[i][i-3] = new Tile('r');
        this->mosaicArray[i][i-4] = new Tile('y');
    }
    */
   /*
    std::string pattern = "byrullbyruulbyrrulbyyrulb";
    int counter = 0;
    for (int i = 0; i < 5; i++){
        for(int j = 0; j<5; j++){
            this->mosaicArray[i][j] = new Tile(pattern[counter]);
            counter++;
        }
    }*/

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
/**
 * If patternlinefullrow == true
 * forloop
 *  If mosaicArray[i][j].getcolour() == lower(c)
 *     mosaicArray[i][j].setcolour(c)   
**/
/*
bool Mosaic::hasFullRow()
{
    bool full;
    for (int row = 0; row < 5; row++)
    {
        full = true;
        bool next = false;
        for (int column = 0; column < 5 && next == false; column++)
        {
            if (!mosaicArray[row][column])
            {
                //skip this row if not full
                full = false;
                next = true;
                }
            }
        if (full){
            return true;
        }
    }
    return false;
}
*/