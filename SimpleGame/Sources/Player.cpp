#include "Player.h"

#include <Game.h>
#include <World/Object/Mob/Mob.h>

Player::Player()
{ }

void Player::Spawn()
{
	mob = Game::Get()->GetWorld()->CreateNewPlayerMob();
}

Mob *Player::GetMob() { return mob; }