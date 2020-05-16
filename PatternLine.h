#ifndef PATTERNLINE_H
#define PATTERNLINE_H

#include "Tile.h"

class PatternLine {
public:
    PatternLine();
    // PatternLine(Tile*** tilePatternArray[5]);
    PatternLine(PatternLine& other);
    ~PatternLine();
    
    // void addTiles(Colour tileColour); //void addTiles(TileFactory tileFactory,int tileFactoryNumber, TileColour colour);
    Tile*** getTilePatternLine(); // get the tile patternline
    //PatternLine lineNumber varies from 1 to 5
    void removeTiles(int lineNumber); // removes all the tiles in the given sub line
    //PatternLine lineNumber varies from 1 to 5
    bool isPatternLineFull(int lineNumber);
    void setTile(int row, int column, Colour colour);
    
private:
    Tile** tilePatternArray[5];  // 5 -> the dimention of the board
    
};

#endif // PATTERNLINE_H