#ifndef FACTORY_TABLE_H
#define FACTORY_TABLE H

#include <vector>
#include <iostream>
#include "Tile.h"

class FactoryTable{

public: 

    FactoryTable();
    FactoryTable(std::vector< std::vector<Tile*> > TableState);
    std::vector< std::vector<Tile*> > getTable();
    std::vector<Tile*>getFactory(int factoryNo);
    void displayFactories();
    int getSize();
    bool factoriesLoaded();
    void setFactoriesLoaded(bool state);
    void addToFactory(int factoryNo, Tile* newTile);

private:

    std::vector< std::vector<Tile*> > tileFactoryTable; // done by dulshan
    bool loaded = false;

};


#endif //FACTORY_TABLE_H