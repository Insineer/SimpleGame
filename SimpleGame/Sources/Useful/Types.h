#pragma once

#include <memory>

template<class T>
using uptr = std::unique_ptr<T>;

template<class T>
using sptr = std::shared_ptr<T>;

template<class T>
using wptr = std::weak_ptr<T>;

#include "Geometry/Vec2.h"
#include "Geometry/Direction.h"
