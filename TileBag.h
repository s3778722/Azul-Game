#ifndef TILEBAG_H
#define TILEBAG_H
#include <iostream>
#include "LinkedList.h"
#include "Tile.h"

class TileBag {
    public:
        TileBag();
        ~TileBag(); 

        void fillBag();
        void shuffle(int seed);
        Tile* drawTileFront();

    private:
        LinkedList* tileList;
};
#endif //TILEBAG_H