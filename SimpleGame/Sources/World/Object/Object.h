#pragma once

class Location;

class Object
{
public:
    // Create and register object in location
    Object(Location *);

    Object(Object &&) = default;
    Object(const Object &) = default;

    virtual ~Object() = default;
};
