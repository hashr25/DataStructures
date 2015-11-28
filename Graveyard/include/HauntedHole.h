#ifndef HAUNTEDHOLE_H
#define HAUNTEDHOLE_H

#include "coord.h"

class HauntedHole : public Tile
{
    public:
        HauntedHole(int, int, int, int, int);

        coord getWarpTo();
        void setWarpTo(coord);

        int getTimeWarp();
        void setTimeWarp(int);

    private:
        coord warpTo;
        int timeWarp;
};

#endif // HAUNTEDHOLE_H
