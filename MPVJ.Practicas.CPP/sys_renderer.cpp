#include "sys_renderer.h"

#include "console.h"
#include "ecs_manager.h"
#include "health.h"
#include "p20data.h"
#include "renderer.h"
#include "transform.h"
#include <iostream>

void SysRenderer::Run() {

  // Print box
  for (int y = 0; y < SIZE_Y; y++)
    for (int x = 0; x < SIZE_X; x++) {
      if (x == MARGIN_X - 1 && y >= MARGIN_Y - 1 && y <= SIZE_Y - MARGIN_Y) {
        fer::cls::GotoXY(x, y);
        std::cout << (unsigned char)124;
      } else if (x == SIZE_X - MARGIN_X && y >= MARGIN_Y - 1 &&
                 y <= SIZE_Y - MARGIN_Y) {
        fer::cls::GotoXY(x, y);
        std::cout << (unsigned char)124;
      } else if (y == MARGIN_Y - 1 && x > MARGIN_X - 1 &&
                 x < SIZE_X - MARGIN_X) {
        fer::cls::GotoXY(x, y);
        std::cout << (unsigned char)45;
      } else if (y == SIZE_Y - MARGIN_Y && x > MARGIN_X - 1 &&
                 x < SIZE_X - MARGIN_X) {
        fer::cls::GotoXY(x, y);
        std::cout << (unsigned char)45;
      }
    }

  // Print entities
  for (auto &entity : entities) {
    auto &tf = ECS::Get().GetComponent<Transform>(entity);
    auto &rd = ECS::Get().GetComponent<Renderer>(entity);
    auto &hp = ECS::Get().GetComponent<Health>(entity);

    if (hp.health == 0)
      continue;

    fer::cls::GotoXY(tf.position.x, tf.position.y);
    std::cout << rd.texture;
  }

  fer::cls::HideCursor();
  Sleep(60);
  fer::cls::Clear();
}
