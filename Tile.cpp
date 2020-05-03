#include "Tile.h"


Tile::Tile(Colour colour) //constructor
{
  this->colour = colour;
}

Tile::~Tile() {} //destructor

Colour Tile::getColour() //get Colour
{
  return this->colour;
}

void Tile::setColour(Colour colour) //set Colour
{
	this->colour = colour;
}

bool Tile::matchTile(Tile* tile) {
  bool matched = false;
  if (this->colour == tile->getColour()){
    matched = true;
  }
  return matched;
}