#ifndef FACTORY_TABLE_H
#define FACTORY_TABLE H

#include <vector>
#include <string> // remove this later
#include <iostream>
#include "Tile.h"

class FactoryTable{

public: 

    FactoryTable();
    FactoryTable(std::vector< std::vector<Tile*> > TableState);
    std::vector< std::vector<Tile*> > getTable();
    std::vector<Tile*>getFactory(int factoryNo);
    void DisplayFactories();
    int getSize();

private:

    std::vector< std::vector<Tile*> > tileFactoryTable; // done by dulshan
    // std::vector<std::vector<Tile>>* Table;

};


#endif //FACTORY_TABLE_H