#ifndef GRAVEYARD_H
#define GRAVEYARD_H

#include <string>
#include <iostream>

#include "Tile.h"

using namespace std;

class Graveyard
{
    public:
        Graveyard(int, int);

        int getWidth();
        void setWidth(int);

        int getHeight();
        void setHeight(int);

        Tile** getGrid();

    private:
        int width;
        int height;
        Tile** grid;
};

#endif // GRAVEYARD_H
