
#include "FactoryTable.h"

FactoryTable::FactoryTable():
    tileFactoryTable()
{
    //Initialises the factory to dots to begin, before they are changed according to whats drawn from the bag.
    //This is also done to aid the loading of the factories via file.
    std::vector<Tile*> firstFactory;
    firstFactory.push_back(new Tile(FIRST_PLAYER));
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

    return tileFactoryTable.at(factoryNo);

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

void FactoryTable::addToFactory(int factoryNo, Tile* newTile){

    tileFactoryTable.at(factoryNo).push_back(newTile);

}

void FactoryTable::factoryPopLastTile(int factoryNo){

    tileFactoryTable.at(factoryNo).pop_back();

}

int FactoryTable::getSize(int factoryNum){
    int size=0;
    for(unsigned int i=0;i<tileFactoryTable.at(factoryNum).size();i++){
        if(tileFactoryTable.at(factoryNum).at(i)->getColour() != NO_TILE && tileFactoryTable.at(factoryNum).at(i)->getColour() != ' '){
            size++;
        }
    }
    return size;
}

bool FactoryTable::isEmpty(){
    bool empty = true;
    for(unsigned int i=0;i<tileFactoryTable.size();i++){
        if(getSize(i)!=0){
            empty = false;
        }
    }
    return empty;
}