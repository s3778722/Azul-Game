#ifndef BOXLID_H
#define BOXLID_H

#include <vector>
#include <string>
#include "Tile.h"

class BoxLid {
public:
    BoxLid();
    ~BoxLid();

    int size();
    void addTile(Tile* tile);
    void clearAll();
    std::string toString();
    std::vector<Tile*> getBoxLid();
    
private:
    std::vector<Tile*> boxLidVector;

};

#endif // BOXLID_H