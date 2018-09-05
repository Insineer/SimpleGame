#pragma once

#include <vector>

#include <Useful/Types.h>

#include "Object/Object.h"

class Location
{
public:
    explicit Location(uf::vec2u size);

    // Register object
    void AddObject(Object *obj);

private:
    uf::vec2u size;

    std::vector<uptr<Object>> objects;
};
