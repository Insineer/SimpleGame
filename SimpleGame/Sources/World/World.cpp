#include "World.h"

#include "Object/Mob/Mob.h"

World::World() :
    location({kLocSizeX, kLocSizeY})
{

}

Mob *World::CreateNewPlayerMob()
{
    return new Mob(&location, {kSpawnX, kSpawnY});
}
