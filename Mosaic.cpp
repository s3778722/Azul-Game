#include "Mosaic.h"

Mosaic::Mosaic(){
    for(int j=0; j<5; j++){
        this->mosaicArray[j] = new Tile*[5];
        for(int i=0;i<5; i++){
            this->mosaicArray[j][i] = new Tile();
        }
    }
}

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

void Mosaic::setMosaic(Tile** array){

}


void Mosaic::displayMosaic(){
}

//sample idea
/*
void Mosaic::mosaicPattern(){
    for(int i = 0; i < 5; i++){
        for (int j = 1; j < 5; ++j){
            this->mosaicArray[i][i] =    'b';
            this->mosaicArray[i][i+j] =  'y';
            this->mosaicArray[i][i+j] =  'r';
            this->mosaicArray[i][i+j] =  'b';
            this->mosaicArray[i][i+j] =  'l';
            this->mosaicArray[i][i-j] =  'l';
            this->mosaicArray[i][i-j] =  'b';
            this->mosaicArray[i][i-j] =  'r';
            this->mosaicArray[j][i-j] =  'y';
        }
    }
}
*/

/**
 * If patternlinefullrow == true
 * forloop
 *  If mosaicArray[i][j].getcolour() == lower(c)
 *     mosaicArray[i][j].setcolour(c)   
**/

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