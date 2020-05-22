#include "TileBag.h"
#include <time.h> 
TileBag::TileBag(){
    tileList = new LinkedList();
    fillBag();
    shuffleRandom();
}

TileBag::TileBag(int seed){
    tileList = new LinkedList();
    fillBag();
    shuffle(seed);
}

TileBag::TileBag(LinkedList* load){
    tileList = load;
}

TileBag::~TileBag(){
    delete tileList;
}
//This just fills the bag one by one before they get randomised later on, 20 tiles per colour.
void TileBag::fillBag(){
    Colour tileColours[5] = {RED, YELLOW, DARK_BLUE, LIGHT_BLUE, BLACK};
    for(int i = 0; i < 20; i++){
        for (Colour colour : tileColours)
        {
            tileList->addBack(new Tile(colour));
        }
    }
}

//Shuffles according to the seed so we can recreate the shuffle process for testing
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
    //swaps tiles according to SEEDED created generator
    for (int i = 0; i < size; i++){
        int swapLoc = uniform_dist(generator);
        std::swap(tiles[i], tiles[swapLoc]);
    }
    for (int i = 0; i < size; i++){
        tileList->addFront(tiles.at(i));
    }
}
//A completely random shuffle if there isn't a seed given
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
    //Randomly swaps tiles according to the generator.
    for (int i = 0; i < size; i++){
        int swapLoc = uniform_dist(generator);
        std::swap(tiles[i], tiles[swapLoc]);
    }
    for (int i = 0; i < size; i++){
        tileList->addFront(tiles.at(i));
    }
}

Tile* TileBag::drawTileFront(){
    return tileList->removeFront();
}

int TileBag::bagSize(){
    return tileList->getSize();
}

Tile* TileBag::getTile(int i){
    return tileList->getTile(i);
}

void TileBag::addTile(Tile* tile){
    tileList->addBack(tile);
}