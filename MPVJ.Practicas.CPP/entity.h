#pragma once

#include "vec.h"

class Entity;
typedef void (*delegate)(Entity &value);

class Entity {
public:
  Vec2i position;
  delegate *behaviour;
  Entity(const Vec2i &pos = {0, 0}, delegate *fun = nullptr);
};
