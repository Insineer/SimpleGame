#pragma once

#include <Player.h>

#include "Location.h"

class World
{
public:
    World();

    Mob *CreateNewPlayerMob();

private:
    Location location;
};
