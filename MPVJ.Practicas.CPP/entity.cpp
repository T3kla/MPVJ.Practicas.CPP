#include "entity.h"

namespace tkl::ent {

Entity::Entity(const Vec2i &pos, delegate *fun)
    : position(pos), behaviour(fun) {}

} // namespace tkl::ent
