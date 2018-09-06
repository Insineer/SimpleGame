#pragma once

#include <Useful/Types.h>

class Mob;

class Player
{
public:
    Player();
    
    void Spawn();

private:
    Mob *mob;
};
