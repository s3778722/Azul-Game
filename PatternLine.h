#ifndef PATTERNLINE_H
#define PATTERNLINE_H

#include "Tile.h"

class PatternLine {
public:
    PatternLine();
    ~PatternLine();
    
    void addTiles(Tile* tile); //void addTiles(TileFactory tileFactory,int tileFactoryNumber, TileColour colour);
    
private:
    
};

#endif // PATTERNLINE_H