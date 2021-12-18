#include "sys_translation.h"

#include "ecs_manager.h"
#include "health.h"
#include "movement.h"
#include "p20data.h"
#include "transform.h"

void SysTranslation::Run() {
  for (auto &entity : entities) {
    auto &tf = ECS::Get().GetComponent<Transform>(entity);
    auto &sp = ECS::Get().GetComponent<Movement>(entity);
    auto &hp = ECS::Get().GetComponent<Health>(entity);

    if (hp.health == 0)
      continue;

    tf.position += sp.speed;

    // Original
    // if (tf.position.x >= SIZE_X - MARGIN_X)
    //  tf.position.x = MARGIN_X;
    // if (tf.position.x < MARGIN_X)
    //  tf.position.x = SIZE_X - MARGIN_X - 1;
    // if (tf.position.y >= SIZE_Y - MARGIN_Y)
    //  tf.position.y = MARGIN_Y;
    // if (tf.position.y < MARGIN_Y)
    //  tf.position.y = SIZE_Y - MARGIN_Y - 1;

    // Rebound
    if (tf.position.x >= SIZE_X - MARGIN_X) {
      tf.position.x = SIZE_X - MARGIN_X - 1;
      sp.speed.x *= -1;
    }
    if (tf.position.x < MARGIN_X) {
      tf.position.x = MARGIN_X;
      sp.speed.x *= -1;
    }
    if (tf.position.y >= SIZE_Y - MARGIN_Y) {
      tf.position.y = SIZE_Y - MARGIN_Y - 1;
      sp.speed.y *= -1;
    }
    if (tf.position.y < MARGIN_Y) {
      tf.position.y = MARGIN_Y;
      sp.speed.y *= -1;
    }
  }
}
