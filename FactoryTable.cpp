
#include "FactoryTable.h"

FactoryTable::FactoryTable(){

    Table =  new std::vector<std::vector<Tile>>;

    for (int i = 0; i < 6; i++) { //6 right now is the number of factories we're going to make
        
        std::vector<Tile>* factory = new std::vector<Tile>;

        for (int j = 0;  j < 4; j++) { //initalising the factory to '.'
            factory->push_back(Tile('.')); 
            std::cout << factory->at(j).getColour() << std::endl;
            std::cout << factory->size() << std::endl;
        }

        Table->push_back(*factory);
        std::cout << Table->size() << std::endl;
  }
}

FactoryTable::FactoryTable(std::vector<std::vector<Tile>>* TableState){

    this->Table = TableState;

}

std::vector<std::vector<Tile>>* FactoryTable::getTable(){

    return Table;

}

std::vector<Tile> FactoryTable::getFactory(int factoryNo){

    return Table->at(factoryNo);

}

void FactoryTable::DisplayFactories(){

    std::cout << Table->size() << std::endl;

    // for (int i = 0; i < Table->size(); i++){

    //     // for (int j = 0; j < Table->at(i).size(); j++){
    //     //     std::cout << Table->at(i).at(j) << std::endl;
    //     // }
    //     std::cout << std::endl;        
    // }


}