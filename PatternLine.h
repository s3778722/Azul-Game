#ifndef PATTERNLINE_H
#define PATTERNLINE_H

#include "Tile.h"

class PatternLine {
public:
    //constructor
    PatternLine();
    // copy constructor
    PatternLine(PatternLine& other);
    // destructor
    ~PatternLine();
    
    // get the tile patternline in raw 2D array
    Tile*** getTilePatternLine(); 
    //removes all the tiles in the given sub line (PatternLine lineNumber varies from 1 to 5)
    void removeTiles(int lineNumber);
    //checks if a pattern line is full (PatternLine lineNumber varies from 1 to 5)
    bool isPatternLineFull(int lineNumber);
    // sets a tile in the patetrn line to a certain colour
    void setTile(int row, int column, Colour colour);
    
private:
    Tile** tilePatternArray[5];  // 5 -> the dimention of the board
    
};

#endif // PATTERNLINE_H