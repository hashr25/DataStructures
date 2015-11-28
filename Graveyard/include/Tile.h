#ifndef TILE_H
#define TILE_H

#include <iostream>

#include "coord.h"

class Tile
{
    public:
        Tile(int, int);

        void setPosition(coord);
        coord getPosition();

        void setColor(char);
        char getColor();

    private:
        coord position;
        int color;
        int type;
};

#endif // TILE_H
