#pragma once

#include <SFML/System.hpp>

#include <Useful/Types.h>

class Location;

class Object
{
public:
    // Create and register object in location
    Object(Location *loc, uf::vec2u pos);

    Object(Object &&) = default;
    Object(const Object &) = default;
    virtual ~Object() = default;

    void Update(sf::Time timeElapsed);

    const uf::vec2u &GetPos() const;

private:
    uf::vec2u pos;
};
