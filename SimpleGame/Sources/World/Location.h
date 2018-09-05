#pragma once

#include <list>

#include "Object/Object.h"

class Location
{
public:
    Location();

private:
    std::list<Object> objects;
};
