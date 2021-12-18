#include "sys_collisions.h"

#include "ecs_manager.h"
#include "health.h"
#include "transform.h"

void SysCollisions::Run() {
  for (auto &a : entities) {

    auto &a_tf = ECS::Get().GetComponent<Transform>(a);
    auto &a_hp = ECS::Get().GetComponent<Health>(a);

    if (a_hp.health == 0)
      continue;

    for (auto &b : entities) {

      if (a == b)
        continue;

      auto &b_tf = ECS::Get().GetComponent<Transform>(b);
      auto &b_hp = ECS::Get().GetComponent<Health>(b);

      if (b_hp.health == 0)
        continue;

      if (a_tf.position == b_tf.position)
        a_hp.health -= 1;
    }
  }
}
