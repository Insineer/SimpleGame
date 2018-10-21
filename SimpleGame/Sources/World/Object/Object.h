#pragma once

#include <SFML/System.hpp>

#include <Graphics/Sprite.h>
#include <Useful/Types.h>

class Location;
class Object
{
public:
	// Create and register object in location
	Object(Location *loc, uf::vec2u pos, Sprite sprite);

	Object(Object &&) = default;
	Object(const Object &) = default;
	virtual ~Object() = default;

	void Update(sf::Time timeElapsed);

	const uf::vec2u &GetPos() const;
	Location *GetLoc() const;
	void Move(const uf::vec2i displacement);

	Sprite sprite;

private:
	uf::vec2u pos;
	Location *loc;
};
