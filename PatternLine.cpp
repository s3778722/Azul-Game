#include "PatternLine.h"

PatternLine::PatternLine(){
    for(int i=0; i<5; i++){ // 5 -> the dimention of the board
        this->tilePatternArray[i] = new Tile*[i+1];
        for(int j=0;j<i+1; j++){
            this->tilePatternArray[i][j] = new Tile();
        }
    }
}

PatternLine::PatternLine(PatternLine& other){
}

PatternLine::~PatternLine(){
    for(int i=0; i<5; i++){
        for(int j=0; j<i; j++){
            delete tilePatternArray[i][j];
        }
        delete[] tilePatternArray[i];
    }
}

void PatternLine::removeTiles(int lineNumber){
    for(int i=0; i<lineNumber; i++){
        tilePatternArray[lineNumber-1][i] = nullptr;
    }
}

Tile*** PatternLine::getTilePatternLine(){
    return tilePatternArray;
}

bool PatternLine::isPatternLineFull(int lineNumber){ //line number here is actual line number -1 due to indexing starting at 0.
    bool isFull = true;
    for(int j=0;j<lineNumber+1;j++){
        if(tilePatternArray[lineNumber][j]->getColour() == '.'){
            isFull = false;
        }
    }
    return isFull; 
}

void PatternLine::setTile(int row, int column, Colour colour){
    tilePatternArray[row][column]->setColour(colour);
}