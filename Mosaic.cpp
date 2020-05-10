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