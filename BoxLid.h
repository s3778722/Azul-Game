#ifndef BOXLID_H
#define BOXLID_H

#include <vector>
#include <string>
#include "Tile.h"

class BoxLid {
public:
    //constructor
    BoxLid();
    //destructor
    ~BoxLid();

    //returns the size of the boxLid
    int size();
    //adds the given tile to the back of the boxLid
    void addTile(Tile* tile);
    // Emoties the boxLid
    void clearAll();
    // String version of the boxLid
    std::string toString();
    // return the whole boxLid vector for later manipulation
    std::vector<Tile*> getBoxLid();
    
private:
    std::vector<Tile*> boxLidVector;

};

#endif // BOXLID_H