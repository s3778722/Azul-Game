
#include "FactoryTable.h"

FactoryTable::FactoryTable():
    tileFactoryTable()
{
    for (int i = 0; i < 6; i++) { //6 right now is the number of factories we're going to make
        
        std::vector<Tile*> factory;

        for (int j = 0;  j < 4; j++) { //initalising the factory to '.'
            factory.push_back(new Tile('.'));
        }

        tileFactoryTable.push_back(factory);
  }
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

void FactoryTable::displayFactories(){

    for (unsigned int i = 0; i < tileFactoryTable.size(); i++){

    std::cout << i <<":";

        for (unsigned int j = 0; j < tileFactoryTable.at(i).size(); j++){
            std::cout << " " << tileFactoryTable.at(i).at(j)->getColour();
        }
        std::cout << std::endl;        
    }

    std::cout << std::endl;
}

int FactoryTable::getSize(){
    return tileFactoryTable.size(); // no of total factories
}