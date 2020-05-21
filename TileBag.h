#ifndef TILEBAG_H
#define TILEBAG_H

#include <iostream>
#include <string>
#include "LinkedList.h"
#include "Tile.h"
#include <vector>
#include <random>

class TileBag {
public:
    // constructor
    TileBag();
    // overloaded constructor with the seed
    TileBag(int seed);
    //overloaded constructor that sets the tile bag to the loaded from save file
    TileBag(LinkedList* load);
    // destructor
    ~TileBag(); 

    // fille the tile bag
    void fillBag();
    // shuffle randomly
    void shuffleRandom(); 
    // shuffle randomly, but because of the seed we will get the same random stuff overall
    void shuffle(int seed);
    // gets the tile at the front
    Tile* drawTileFront();
    // get the tile bag size
    int bagSize();
    // get the tile at the given index
    Tile* getTile(int i);

private:
    LinkedList* tileList;
};
#endif //TILEBAG_H