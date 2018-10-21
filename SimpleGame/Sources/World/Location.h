#pragma once

#include <vector>

#include <SFML/System.hpp>

#include <Useful/Types.h>

#include "Object/Object.h"

class Location
{
public:
	explicit Location(uf::vec2u size);

	void Update(sf::Time timeElapsed);

	// Register object
	void AddObject(Object *obj);
	std::vector<uptr<Object>> &GetObjects();

private:
	uf::vec2u size;

	std::vector<uptr<Object>> objects;
};
