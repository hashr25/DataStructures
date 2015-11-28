#include "HauntedHole.h"

HauntedHole::HauntedHole(int xPos, int yPos, int xWarp, int yWarp, int timeWarp)
{
    coord pos;
    pos.x = xPos;
    pos.y = yPos;
    setPosition(pos);

    coord warp;
    warp.x = xWarp;
    warp.y = yWarp;
    setWarpTo(warp);

    setTimeWarp(timeWarp);
}


coord HauntedHole::getWarpTo()
{
    return warpTo;
}

void HauntedHole::setWarpTo(coord warpTo)
{
    this -> warpTo = warpTo;
}


int HauntedHole::getTimeWarp()
{
    return timeWarp;
}

void HauntedHole::setTimeWarp(int timeWarp)
{
    this -> timeWarp = timeWarp;
}
