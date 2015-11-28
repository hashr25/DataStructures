#include "Tile.h"

Tile::Tile(int x, int y)
{
    coord position;
    position.x = x;
    position.y = y;

    setPosition(position);
}

coord Tile::getPosition()
{
    return position;
}

void Tile::setPosition(coord position)
{
    this -> position = position;
}
