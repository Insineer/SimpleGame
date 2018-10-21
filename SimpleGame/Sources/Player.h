#pragma once

#include <Useful/Types.h>
#include <World/Object/Mob/Mob.h>

class Player
{
public:
	Player();
	
	void Spawn();
	
	Mob *GetMob();

private:
	Mob *mob;
};
