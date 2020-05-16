#include "PatternLine.h"

PatternLine::PatternLine(){
    for(int i=0; i<5; i++){ // 5 -> the dimention of the board
        this->tilePatternArray[i] = new Tile*[i+1];
        for(int j=0;j<i+1; j++){
            this->tilePatternArray[i][j] = new Tile();
        }
    }
}

// PatternLine::PatternLine(Tile** tilePatternArray[5]){
//     *this->tilePatternArray = *tilePatternArray;
// }

PatternLine::PatternLine(PatternLine& other){
}

PatternLine::~PatternLine(){ // not sure if this is needed so check later - not needed since nothing is in the heap
    for(int i=0; i<5; i++){
        for(int j=0; j<i; j++){
        // delete[] tilePatternArray[i];
            delete tilePatternArray[i][j];
        }
    }
    // delete[] tilePatternArray;
}

void PatternLine::removeTiles(int lineNumber){
    for(int i=0; i<lineNumber; i++){
        tilePatternArray[lineNumber-1][i] = nullptr;
    }
}

Tile*** PatternLine::getTilePatternLine(){
    return tilePatternArray;
}

// int PatternLine::getPatternLineSizeIndi(int lineNumber){

// }

bool PatternLine::isPatternLineFull(int lineNumber){
    bool isFull = true;
    for(int j=0;j<lineNumber;j++){
        if(tilePatternArray[lineNumber-1][j]->getColour() == '.'){
            isFull = false;
        }
    }
    return isFull; 
}

void PatternLine::setTile(int row, int column, Colour colour){
    tilePatternArray[row][column]->setColour(colour);
}