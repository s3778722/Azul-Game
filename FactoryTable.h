#ifndef FACTORY_TABLE_H
#define FACTORY_TABLE H

#include <vector>

#include "Tile.h"

class FactoryTable{

public: 

    FactoryTable();
    FactoryTable(std::vector<std::vector<Tile>> TableState);
    std::vector<std::vector<Tile>> getTable();
    std::vector<Tile> FactoryTable::getFactory(int factoryNo);

private:

    std::vector<std::vector<Tile>> Table;

};


#endif //FACTORY_TABLE_H