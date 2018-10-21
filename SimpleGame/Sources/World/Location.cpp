#include "Location.h"

Location::Location(uf::vec2u size) :
	size(size)
{ }

void Location::Update(sf::Time timeElapsed)
{
	for (auto &obj : objects)
		obj->Update(timeElapsed);
}

void Location::AddObject(Object *obj)
{
	objects.push_back(uptr<Object>(obj));
}

std::vector<uptr<Object>> &Location::GetObjects() { return objects; }
