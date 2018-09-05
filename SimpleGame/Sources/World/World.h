#pragma once

#include <Player.h>
#include <Useful/Types.h>

#include "Location.h"

class World
{
public:
    World();

    Mob *CreateNewPlayerMob();

private:
    Location location;

// constants
    static const uint8_t kLocSizeX = 100;
    static const uint8_t kLocSizeY = 100;
    static const uint8_t kSpawnX = 50;
    static const uint8_t kSpawnY = 50;
};
