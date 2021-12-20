#pragma once

#include <chrono>
#include <iostream>
#include <list>
#include <random>

#include "p20data.h"

#include "console.h"
#include "vec.h"

#include "ecs_manager.h"

#include "ent.h"

#include "sys_collisions.h"
#include "sys_renderer.h"
#include "sys_translation.h"

#include "health.h"
#include "movement.h"
#include "renderer.h"
#include "transform.h"

using RangeInt = std::uniform_int_distribution<int>;
using RandGen = std::default_random_engine;

int HowManyAlive(const std::list<Ent> &entities);
void ReviveSome(const std::list<Ent> &entities, int alive);

void RunP20() {
  // ECS Startup
  auto &ecs = ECS::Get();
  ecs.Init();

  //    Component Registration
  ecs.RegisterComponent<Transform>();
  ecs.RegisterComponent<Movement>();
  ecs.RegisterComponent<Renderer>();
  ecs.RegisterComponent<Health>();

  //    System Registration
  auto sysTran = ecs.RegisterSystem<SysTranslation>();
  auto sysColl = ecs.RegisterSystem<SysCollisions>();
  auto sysRend = ecs.RegisterSystem<SysRenderer>();

  //    Movement: move entities
  Signature signMove;
  signMove.set(ecs.GetComponentID<Transform>());
  signMove.set(ecs.GetComponentID<Health>());
  signMove.set(ecs.GetComponentID<Movement>());
  ecs.SetSystemSignature<SysTranslation>(signMove);

  //    Collisions: health and rebounds
  Signature signColl;
  signColl.set(ecs.GetComponentID<Transform>());
  signColl.set(ecs.GetComponentID<Health>());
  ecs.SetSystemSignature<SysCollisions>(signColl);

  //    Renderer: render if alive
  Signature signRend;
  signRend.set(ecs.GetComponentID<Transform>());
  signRend.set(ecs.GetComponentID<Health>());
  signRend.set(ecs.GetComponentID<Renderer>());
  ecs.SetSystemSignature<SysRenderer>(signRend);

  // Entities Initialization
  auto now = std::chrono::system_clock::now();
  RandGen rand((unsigned int)now.time_since_epoch().count());
  RangeInt randPosX(MARGIN_X, SIZE_X - MARGIN_X);
  RangeInt randPosY(MARGIN_Y, SIZE_Y - MARGIN_Y);
  RangeInt randChar(0, 255);
  RangeInt randColr(1, 14);
  RangeInt randSpeedX(MIN_SPEED_X, MAX_SPEED_X);
  RangeInt randSpeedY(MIN_SPEED_Y, MAX_SPEED_Y);
  RangeInt randHP(1, MAX_HP);

  auto entities = std::list<Ent>(MAX_ENTITIES);

  for (auto &entity : entities) {

    EntID id = ecs.CreateEntity();

    entity.SetEntID(id);

    Transform tf;
    tf.position = {randPosX(rand), randPosY(rand)};
    ecs.AddComponent(id, tf);

    Movement mv;
    mv.speed = {randSpeedX(rand), randSpeedY(rand)};
    ecs.AddComponent(id, mv);

    Health hp;
    hp.health = randHP(rand);
    ecs.AddComponent(id, hp);

    Renderer rd;
    rd.texture = (char)randChar(rand);
    rd.color = randColr(rand);
    ecs.AddComponent(id, rd);
  }

  while (true) {
    sysTran->Run();
    sysColl->Run();
    sysRend->Run();

    int alive = HowManyAlive(entities);
    if (alive < MIN_ENTITIES) {
      ReviveSome(entities, alive);
    }
  }
}

int HowManyAlive(const std::list<Ent> &entities) {
  int num = 0;

  for (auto &entity : entities) {
    auto &hp = ECS::Get().GetComponent<Health>(entity.GetEntID());
    num += hp.health > 0 ? 1 : 0;
  }

  return num;
}

void ReviveSome(const std::list<Ent> &entities, int alive) {
  auto now = std::chrono::system_clock::now();
  RandGen gen((unsigned int)now.time_since_epoch().count());
  RangeInt randLuck(0, 1);
  RangeInt randRes(1, (MAX_ENTITIES - alive) / 2);
  RangeInt randHP(1, MAX_HP);

  int toRevive = randRes(gen);
  int revived = 0;

  do {
    for (auto &entity : entities) {
      auto &hp = ECS::Get().GetComponent<Health>(entity.GetEntID());

      if (hp.health != 0 || randLuck(gen))
        continue;

      hp.health = randHP(gen);
      revived++;
      break;
    }
  } while (revived < toRevive);
}
