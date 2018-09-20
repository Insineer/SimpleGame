#include "World.h"

#include "Object/Mob/Mob.h"

World::World() :
    location({kLocSizeX, kLocSizeY})
{

}

void World::Update(sf::Time timeElapsed)
{
	location.Update(timeElapsed);
}

Mob *World::CreateNewPlayerMob()
{
    return new Mob(&location, {kSpawnX, kSpawnY});
}
