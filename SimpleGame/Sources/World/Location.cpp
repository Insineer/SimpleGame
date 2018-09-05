#include "Location.h"

Location::Location(uf::vec2u size) :
    size(size)
{ }

void Location::AddObject(Object *obj)
{
    objects.push_back(uptr<Object>(obj));
}
