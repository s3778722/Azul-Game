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
    TileBag();
    TileBag(LinkedList* load);
    ~TileBag(); 

    void fillBag();
    void shuffleRandom(); 
    void shuffle(int seed); //for testing
    Tile* drawTileFront();
    int bagSize();
    Tile* getTile(int i);

private:
    LinkedList* tileList;
};
#endif //TILEBAG_H