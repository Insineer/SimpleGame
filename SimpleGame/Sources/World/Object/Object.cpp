#include "Object.h"

#include <World/Location.h>

Object::Object(Location *loc)
{
    loc->AddObject(this);
}
