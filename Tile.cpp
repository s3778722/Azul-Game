#include "Tile.h"

Tile::Tile(Colour colour)
{
  this->colour = colour;
}

Colour Tile::getColour()
{
  return this->colour;
}

void Tile::setColour(Colour colour)
{
	this->colour = colour;
}