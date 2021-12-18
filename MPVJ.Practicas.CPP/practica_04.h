#pragma once

#include "console.h"
#include "entity.h"
#include "vec.h"
#include <Windows.h>
#include <iostream>
#include <memory>

using namespace tkl::ent;

namespace P04 {

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
  if (value.x >= P04::size_x - P04::margin_x)
    value.x = P04::margin_x;
  if (value.x < P04::margin_x)
    value.x = P04::size_x - P04::margin_x - 1;

  if (value.y >= P04::size_y - P04::margin_y)
    value.y = P04::margin_y;
  if (value.y < P04::margin_y)
    value.y = P04::size_y - P04::margin_y - 1;
}

} // namespace P04

void RunP04() {
  // Entity initialization
  delegate del_01[2] = {&P04::draw_01, &P04::move_01};
  delegate del_02[2] = {&P04::draw_02, &P04::move_02};
  delegate del_03[2] = {&P04::draw_03, &P04::move_03};
  delegate del_04[2] = {&P04::draw_04, &P04::move_04};

  std::unique_ptr<Entity> entities[4] = {
      std::make_unique<Entity>(Vec2i(18, 20), del_01),
      std::make_unique<Entity>(Vec2i(36, 8), del_02),
      std::make_unique<Entity>(Vec2i(57, 15), del_03),
      std::make_unique<Entity>(Vec2i(75, 25), del_04)};

  while (true) {
    // Print random message
    const char *lri = "La rica interfaz";
    int y = P04::margin_y - 2;
    int x = (int)floorf(P04::margin_x + P04::size_x / 2.0f - 16);
    for (int i = 0; i < y; i++)
      std::cout << std::endl;
    for (int i = 0; i < x; i++)
      std::cout << ' ';
    std::cout << lri << std::endl;

    // Print box
    for (y = 0; y < P04::size_y; y++)
      for (x = 0; x < P04::size_x; x++) {
        if (x == P04::margin_x - 1 && y >= P04::margin_y - 1 &&
            y <= P04::size_y - P04::margin_y) {
          fer::cls::GotoXY(x, y);
          std::cout << (unsigned char)124;
        } else if (x == P04::size_x - P04::margin_x && y >= P04::margin_y - 1 &&
                   y <= P04::size_y - P04::margin_y) {
          fer::cls::GotoXY(x, y);
          std::cout << (unsigned char)124;
        } else if (y == P04::margin_y - 1 && x > P04::margin_x - 1 &&
                   x < P04::size_x - P04::margin_x) {
          fer::cls::GotoXY(x, y);
          std::cout << (unsigned char)45;
        } else if (y == P04::size_y - P04::margin_y && x > P04::margin_x - 1 &&
                   x < P04::size_x - P04::margin_x) {
          fer::cls::GotoXY(x, y);
          std::cout << (unsigned char)45;
        }
      }

    // Move and print entities
    for (size_t i = 0; i < 4; i++) {
      entities[i]->behaviour[1](*entities[i]);
      P04::validate_pos(entities[i]->position);
      entities[i]->behaviour[0](*entities[i]);
    }

    fer::cls::HideCursor();
    Sleep(60);
    fer::cls::Clear();
  }
}
