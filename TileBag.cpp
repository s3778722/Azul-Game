#include "TileBag.h"
#include <time.h> 
TileBag::TileBag(){
    tileList = new LinkedList();
    fillBag();
    shuffleRandom();
}

TileBag::TileBag(LinkedList* load){
    tileList = load;
}

TileBag::~TileBag(){
    delete tileList;
}

void TileBag::fillBag(){
    Colour tileColours[5] = {RED, YELLOW, DARK_BLUE, LIGHT_BLUE, BLACK};
    for(int i = 0; i < 20; i++){
        for (Colour colour : tileColours)
        {
            tileList->addBack(new Tile(colour));
        }
    }
}

//for testing
void TileBag::shuffle(int seed){
    int size = tileList->getSize();
    std::vector<Tile*> tiles;
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> uniform_dist(0, size-1);
    for (int i = 0; i < size; i++){
        //take front tile and push to back
        tiles.push_back(tileList->getTile(0));
        tileList->removeFront();
    }
    for (int i = 0; i < size; i++){
        int swapLoc = uniform_dist(generator);
        std::swap(tiles[i], tiles[swapLoc]);
    }
    for (int i = 0; i < size; i++){
        tileList->addFront(tiles.at(i));
    }
}

void TileBag::shuffleRandom(){
    int size = tileList->getSize();
    std::vector<Tile*> tiles;
    std::default_random_engine generator(time(0));
    std::uniform_int_distribution<int> uniform_dist(0, size-1);
    for (int i = 0; i < size; i++){
        //take front tile and push to back
        tiles.push_back(tileList->getTile(0));
        tileList->removeFront();
    }
    for (int i = 0; i < size; i++){
        int swapLoc = uniform_dist(generator);
        std::swap(tiles[i], tiles[swapLoc]);
    }
    for (int i = 0; i < size; i++){
        tileList->addFront(tiles.at(i));
    }
}

Tile* TileBag::drawTileFront(){
    // Tile* frontTile = tileList->getTile(0);
    // tileList->removeFront();
    return tileList->removeFront();
}

int TileBag::bagSize(){
    return tileList->getSize();
}

Tile* TileBag::getTile(int i){
    return tileList->getTile(i);
}