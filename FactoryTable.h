#ifndef FACTORY_TABLE_H
#define FACTORY_TABLE H

#include <vector>
#include <iostream>
#include "Tile.h"

class FactoryTable{

public: 

    //constructor
    FactoryTable();
    //destructor
    ~FactoryTable();
    //overloaded constructor which setes the factories to the given table state
    FactoryTable(std::vector< std::vector<Tile*> > TableState);
    // get the raw factory table 2D vector
    std::vector< std::vector<Tile*> > getTable();
    // get the raw factory vector that's denoted by the factory number
    std::vector<Tile*>getFactory(int factoryNo);
    // display the factories
    void displayFactories();
    // get size of the factories, always will return 6
    int getSize();
    //gives the size of the relevant factory only counts the ones with an colour that is not NO_TILE
    int getSize(int factoryNum);
    // returns true if the factories were loaded from a file
    bool factoriesLoaded();
    // sets the factories loaded to the given state 
    void setFactoriesLoaded(bool state);
    // adds the tile to the given factory denoted by the factory number
    void addToFactory(int factoryNo, Tile* newTile);
    // removed the last tile of the given factory
    void factoryPopLastTile(int factoryNo);
    //checks if all the factories are empty(including the zeroth one)
    bool isEmpty();

private:

    std::vector< std::vector<Tile*> > tileFactoryTable; // done by dulshan
    bool loaded = false;

};


#endif //FACTORY_TABLE_H