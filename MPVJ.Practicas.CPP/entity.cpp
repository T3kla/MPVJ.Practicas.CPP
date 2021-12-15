#include "entity.h"

Entity::Entity(const point_i &position, delegate *behaviour)
    : position(position), behaviour(behaviour) {}
