#include "Object.h"

#include <World/Location.h>

Object::Object(Location *loc, uf::vec2u pos) :
    pos(pos)
{
    loc->AddObject(this);
}

void Object::Update(sf::Time timeElapsed)
{

}

const uf::vec2u &Object::GetPos() const { return pos; }
