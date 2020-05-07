#include "Mosaic.h"
#include <iostream>

Mosiac::Mosiac(){

    for (int i = 0; i < 5; i++){

        for (int j = 0;  j < 5; j++) { //initalising the mosiac to '.'
                mosiacArray[i][j] = (Tile('.'));
                std::cout << mosiacArray[i][j].getColour();
            }
            std::cout << std::endl;

    }

}

Mosiac::~Mosiac(){


}

std::array<std::array<Tile,5>,5> getMosiac(){




}

void setMosiac(std::array<std::array<Tile,5>,5> array){



}


void displayMosaic(){



}