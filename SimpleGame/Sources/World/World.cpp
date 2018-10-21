#include "World.h"

#include <Game.h>
#include "Object/Mob/Mob.h"

World::World() :
	location({kLocSizeX, kLocSizeY})
{
}

void World::Init()
{
	new Object(&location, uf::vec2u{kSpawnX+1, kSpawnY}*32, Game::Get()->GetRM()->GetSprite(1));
}

void World::Update(sf::Time timeElapsed)
{
	location.Update(timeElapsed);
}

Mob *World::CreateNewPlayerMob()
{
	return new Mob(&location, uf::vec2u{kSpawnX, kSpawnY}*32, Game::Get()->GetRM()->GetSprite(2));
}
