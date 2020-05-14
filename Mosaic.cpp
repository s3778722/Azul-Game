#include "Mosaic.h"

Mosaic::Mosaic(){
    for(int j=0; j<5; j++){
        this->mosaicArray[j] = new Tile*[5];
        for(int i=0;i<5; i++){
            this->mosaicArray[j][i] = new Tile();
        }
    }  
    mosaicPattern();
    displayMosaic();
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
    //char a[] = {'B','Y','R','U','L'};
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if(islower(mosaicArray[i][j]->getColour()))
            {
                mosaicArray[i][j] = new Tile();
            }
        }
    }
}

//sample idea
void Mosaic::mosaicPattern(){
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