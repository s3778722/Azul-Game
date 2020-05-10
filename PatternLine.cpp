#include "PatternLine.h"

PatternLine::PatternLine(){
    for(int i=0; i<5; i++){ // 5 -> the dimention of the board
        Tile* subArray[i+1];
        this->tilePatternArray[i] = subArray;
    }
}

PatternLine::PatternLine(PatternLine& other){
}

PatternLine::~PatternLine(){ // not sure if this is needed so check later - not needed since nothing is in the heap
    // for(int i=0; i<5; i++){
    //     for(int j=0; j<i; j++){
    //     // delete[] tilePatternArray[i];
    //         delete tilePatternArray[i][j];
    //     }
    // }
    // delete[] tilePatternArray;
}

void PatternLine::removeTiles(int lineNumber){
    for(int i=0; i<lineNumber; i++){
        tilePatternArray[lineNumber][i] = nullptr;
    }
}

Tile*** PatternLine::getTilePatternLine(){
    return tilePatternArray;
}