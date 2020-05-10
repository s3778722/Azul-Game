#ifndef PATTERNLINE_H
#define PATTERNLINE_H

#include "Tile.h"

class PatternLine {
public:
    PatternLine();
    PatternLine(PatternLine& other);
    ~PatternLine();
    
    // void addTiles(Colour tileColour); //void addTiles(TileFactory tileFactory,int tileFactoryNumber, TileColour colour);
    Tile*** getTilePatternLine(); // get the tile patternline
    void removeTiles(int lineNumber); // removes all the tiles in the given sub line
    // int getPatternLineSizeIndi(int lineNumber);
    
private:
    Tile** tilePatternArray[5];  // 5 -> the dimention of the board
    
};

#endif // PATTERNLINE_H