#pragma once

#include <Useful/Types.h>

class Mob;

class Player
{
public:
    Player();
    
    //Player(Player&&) = default;

private:
    Mob *mob;
};
