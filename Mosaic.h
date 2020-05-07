#include <array>
#include "Tile.h"

class Mosiac {
public:

    Mosiac();
    ~Mosiac();
    std::array<std::array<Tile,5>,5> getMosiac();
    void setMosiac(std::array<std::array<Tile,5>,5> array);
    void displayMosaic();

    
private:

    std::array<std::array<Tile,5>,5> mosiacArray;
    
};