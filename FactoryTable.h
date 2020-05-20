#ifndef FACTORY_TABLE_H
#define FACTORY_TABLE H

#include <vector>
#include <iostream>
#include "Tile.h"

class FactoryTable{

public: 

    FactoryTable();
    ~FactoryTable();
    FactoryTable(std::vector< std::vector<Tile*> > TableState);
    std::vector< std::vector<Tile*> > getTable();
    std::vector<Tile*>getFactory(int factoryNo);
    void displayFactories();
    int getSize();
    //gives the size of the relevant factory only counts the ones with an colour that is not NO_TILE
    int getSize(int factoryNum);
    bool factoriesLoaded();
    void setFactoriesLoaded(bool state);
    void addToFactory(int factoryNo, Tile* newTile);
    void factoryPopLastTile(int factoryNo);
    //checks if all the factories are empty(including the zeroth one)
    bool isEmpty();

private:

    std::vector< std::vector<Tile*> > tileFactoryTable; // done by dulshan
    bool loaded = false;

};


#endif //FACTORY_TABLE_H