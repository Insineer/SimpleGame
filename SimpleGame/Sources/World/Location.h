#pragma once

#include <vector>

#include <Useful/Types.h>

#include "Object/Object.h"

class Location
{
public:
    Location();

    // Register object
    void AddObject(Object *);

private:
    std::vector<uptr<Object>> objects;
};
