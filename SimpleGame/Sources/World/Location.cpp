#include "Location.h"

Location::Location()
{

}

void Location::AddObject(Object *obj)
{
    objects.push_back(uptr<Object>(obj));
}
