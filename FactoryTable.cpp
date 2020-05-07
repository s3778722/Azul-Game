
#include "FactoryTable.h"

FactoryTable::FactoryTable():
    tileFactoryTable()
{
}

FactoryTable::FactoryTable(std::vector< std::vector<Tile*> > TableState){

    this->tileFactoryTable = TableState;

}

std::vector< std::vector<Tile*> > FactoryTable::getTable(){

    return tileFactoryTable;

}

std::vector<Tile*> FactoryTable::getFactory(int factoryNo){

    return tileFactoryTable[factoryNo];

}

void FactoryTable::DisplayFactories(){

    std::cout << this->getSize() << std::endl;

}

int FactoryTable::getSize(){
    return 0;
}