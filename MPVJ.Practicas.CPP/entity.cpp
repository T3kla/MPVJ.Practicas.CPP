#include "entity.h"

Entity::Entity(const Vec2i &pos, delegate *fun)
    : position(pos), behaviour(fun) {}
