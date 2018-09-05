#include "World.h"

#include "Object/Mob/Mob.h"

World::World() 
{

}

Mob *World::CreateNewPlayerMob()
{
    return new Mob(&location);
}
