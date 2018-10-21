#include "Object.h"

#include <World/Location.h>

Object::Object(Location *loc, uf::vec2u pos, Sprite sprite) :
	sprite(sprite),
	pos(pos),
	loc(loc)
{
	loc->AddObject(this);
}

void Object::Update(sf::Time timeElapsed)
{

}

void Object::Move(const uf::vec2i displacement)
{
	pos += displacement;
}

const uf::vec2u &Object::GetPos() const { return pos; }
Location *Object::GetLoc() const { return loc; }
