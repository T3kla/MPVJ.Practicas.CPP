#pragma once

#include "console.h"
#include "entity.h"
#include "vec.h"
#include <Windows.h>
#include <iostream>
#include <memory>

using namespace tkl::ent;

namespace p04 {

static int size_x = 120;
static int size_y = 25;
static int margin_x = 10;
static int margin_y = 4;

void draw_01(Entity &value) {
  fer::cls::GotoXY(value.position.x, value.position.y);
  std::cout << '*';
}

void move_01(Entity &value) {
  value.position.x++;
  value.position.y++;
}

void draw_02(Entity &value) {
  fer::cls::GotoXY(value.position.x, value.position.y);
  std::cout << '&';
}

void move_02(Entity &value) {
  value.position.x++;
  value.position.y--;
}

void draw_03(Entity &value) {
  fer::cls::GotoXY(value.position.x, value.position.y);
  std::cout << '~';
}

void move_03(Entity &value) {
  value.position.x--;
  value.position.y++;
}

void draw_04(Entity &value) {
  fer::cls::GotoXY(value.position.x, value.position.y);
  std::cout << '#';
}

void move_04(Entity &value) {
  value.position.x--;
  value.position.y--;
}

void validate_pos(Vec2i &value) {
  if (value.x >= p04::size_x - p04::margin_x)
    value.x = p04::margin_x;
  if (value.x < p04::margin_x)
    value.x = p04::size_x - p04::margin_x - 1;

  if (value.y >= p04::size_y - p04::margin_y)
    value.y = p04::margin_y;
  if (value.y < p04::margin_y)
    value.y = p04::size_y - p04::margin_y - 1;
}

} // namespace p04

void run_practica_04() {

  delegate del_01[2] = {&p04::draw_01, &p04::move_01};
  delegate del_02[2] = {&p04::draw_02, &p04::move_02};
  delegate del_03[2] = {&p04::draw_03, &p04::move_03};
  delegate del_04[2] = {&p04::draw_04, &p04::move_04};

  std::unique_ptr<Entity> entities[4] = {
      std::make_unique<Entity>(Vec2i(18, 20), del_01),
      std::make_unique<Entity>(Vec2i(36, 8), del_02),
      std::make_unique<Entity>(Vec2i(57, 15), del_03),
      std::make_unique<Entity>(Vec2i(75, 25), del_04)};

  while (true) {
    const char *lri = "La rica interfaz";
    int y = p04::margin_y - 2;
    int x = (int)floorf(p04::margin_x + p04::size_x / 2.0f - 16);

    for (int i = 0; i < y; i++)
      std::cout << std::endl;
    for (int i = 0; i < x; i++)
      std::cout << ' ';
    std::cout << lri << std::endl;

    for (y = 0; y < p04::size_y; y++)
      for (x = 0; x < p04::size_x; x++) {
        if (x == p04::margin_x - 1 && y >= p04::margin_y - 1 &&
            y <= p04::size_y - p04::margin_y) {
          fer::cls::GotoXY(x, y);
          std::cout << (unsigned char)124;
        } else if (x == p04::size_x - p04::margin_x && y >= p04::margin_y - 1 &&
                   y <= p04::size_y - p04::margin_y) {
          fer::cls::GotoXY(x, y);
          std::cout << (unsigned char)124;
        } else if (y == p04::margin_y - 1 && x > p04::margin_x - 1 &&
                   x < p04::size_x - p04::margin_x) {
          fer::cls::GotoXY(x, y);
          std::cout << (unsigned char)45;
        } else if (y == p04::size_y - p04::margin_y && x > p04::margin_x - 1 &&
                   x < p04::size_x - p04::margin_x) {
          fer::cls::GotoXY(x, y);
          std::cout << (unsigned char)45;
        }
      }

    for (size_t i = 0; i < 4; i++) {
      entities[i]->behaviour[1](*entities[i]);
      p04::validate_pos(entities[i]->position);
      entities[i]->behaviour[0](*entities[i]);
    }

    fer::cls::HideCursor();
    Sleep(60);
    fer::cls::Clear();
  }
}
