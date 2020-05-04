
#include "FactoryTable.h"

FactoryTable::FactoryTable(){

    for (int i; i < 6; i++){ //6 right now is the number of factories we're going to make
        for (int j; j < 4; j++){ // initalising the factory to '.'

            Tile tile('.');
            Table.at(i).push_back(tile);

        } 
    }
}

FactoryTable::FactoryTable(std::vector<std::vector<Tile>> TableState){

    this->Table = TableState;

}

std::vector<std::vector<Tile>> FactoryTable::getTable(){

    return Table;

}

std::vector<Tile> FactoryTable::getFactory(int factoryNo){

    return Table.at(factoryNo);

}