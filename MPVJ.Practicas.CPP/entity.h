#pragma once

#include "point.h"

struct Entity;
typedef void (*delegate)(Entity &value);

struct Entity {
  point_i position;
  delegate *behaviour;
  Entity(const point_i &position = point_i(0, 0),
         delegate *behaviour = nullptr);
};
