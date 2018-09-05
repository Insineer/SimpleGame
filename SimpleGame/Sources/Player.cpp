#include "Player.h"

#include <Game.h>
#include <World/Object/Mob/Mob.h>

Player::Player()
{ 
    mob = Game::Get()->GetWorld()->CreateNewPlayerMob();
}
