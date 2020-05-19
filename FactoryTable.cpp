
#include "FactoryTable.h"

FactoryTable::FactoryTable():
    tileFactoryTable()
{

    std::vector<Tile*> firstFactory;
    firstFactory.push_back(new Tile('F'));
    tileFactoryTable.push_back(firstFactory);

    for (int i = 1; i < 6; i++) { //6 right now is the number of factories we're going to make
        
        std::vector<Tile*> factory;

        for (int j = 0;  j < 4; j++) { //initalising the factory to '.'
            factory.push_back(new Tile('.'));
        }

        tileFactoryTable.push_back(factory);
  }
}

FactoryTable::~FactoryTable(){
    for (unsigned int i = 0; i < tileFactoryTable.size(); i++){
        for (unsigned int j = 0; j < tileFactoryTable.at(i).size(); j++){
            delete tileFactoryTable.at(i).at(j);
        }
        tileFactoryTable.at(i).clear();//      
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
            if (tileFactoryTable.at(i).at(j)->getColour() != '.'){
                std::cout << " " << tileFactoryTable.at(i).at(j)->getColour();
            }
        }
        std::cout << std::endl;        
    }

    std::cout << std::endl;
}

int FactoryTable::getSize(){
    return tileFactoryTable.size(); // no of total factories
}

bool FactoryTable::factoriesLoaded(){
    return loaded;
}

void FactoryTable::setFactoriesLoaded(bool state){
    loaded = state;
}

// void FactoryTable::setTile(int row, int column, Colour colour){
//     tileFactoryTable.at(row).at(column)->setColour(colour);
// }