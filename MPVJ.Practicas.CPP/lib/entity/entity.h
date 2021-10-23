#pragma once

#include "..\point\point.h"

struct entity;
typedef void (*delegate)(entity &value);

struct entity
{
    point_i position;
    delegate *behaviour;
    entity(const point_i &position = point_i(0, 0), delegate *behaviour = nullptr);
};
