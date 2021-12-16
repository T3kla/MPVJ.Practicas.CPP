#pragma once

#include "player.h"
#include <iostream>

using namespace tkl::bit;

void run_practica_01() {

  Player p;

  std::cout << "> Testing set_health and get_health" << std::endl << std::endl;

  std::cout << "    set_health(30)" << std::endl;
  p.SetHealth(30);
  std::cout << "        get_health(): " << p.GetHealth() << std::endl;

  std::cout << "    set_health(25)" << std::endl;
  p.SetHealth(25);
  std::cout << "        get_health(): " << p.GetHealth() << std::endl;

  std::cout << std::endl;

  std::cout << "> Testing add_bullets and get_bullets" << std::endl
            << std::endl;

  std::cout << "    add_bullets(30)" << std::endl;
  p.AddBullets(30);
  std::cout << "        get_bullets(): " << p.GetBullets() << std::endl;

  std::cout << "    add_bullets(25)" << std::endl;
  p.AddBullets(25);
  std::cout << "        get_bullets(): " << p.GetBullets() << std::endl;

  std::cout << std::endl;

  std::cout << "> Testing set_brothers and get_brothers" << std::endl
            << std::endl;

  std::cout << "    set_brothers(4)" << std::endl;
  p.GetBrothers(4);
  std::cout << "        get_brothers(): " << p.GetBrothers() << std::endl;

  std::cout << "    set_brothers(11)" << std::endl;
  p.GetBrothers(11);
  std::cout << "        get_brothers(): " << p.GetBrothers() << std::endl;

  std::cout << std::endl;

  std::cout << "> Testing set_berserker and is_berserker" << std::endl
            << std::endl;

  std::cout << "    set_berserker(true)" << std::endl;
  p.SetBerserker(true);
  std::cout << "        is_berserker(): " << p.IsBerserker() << std::endl;

  std::cout << "    set_berserker(false)" << std::endl;
  p.SetBerserker(false);
  std::cout << "        is_berserker(): " << p.IsBerserker() << std::endl;

  std::cout << std::endl;

  std::cout << "> Testing set_shield and is_shield" << std::endl << std::endl;

  std::cout << "    set_shield(true)" << std::endl;
  p.SetShield(true);
  std::cout << "        is_shield(): " << p.IsShield() << std::endl;

  std::cout << "    set_shield(false)" << std::endl;
  p.SetShield(false);
  std::cout << "        is_shield(): " << p.IsShield() << std::endl;

  std::cout << std::endl;

  std::cout << "> Testing set_infBullets and is_infBullets" << std::endl
            << std::endl;

  std::cout << "    set_infBullets(true)" << std::endl;
  p.SetHackInfiniteBullets(true);
  std::cout << "        is_infBullets(): " << p.IsHackInfiniteBullets()
            << std::endl;

  std::cout << "    set_infBullets(false)" << std::endl;
  p.SetHackInfiniteBullets(false);
  std::cout << "        is_infBullets(): " << p.IsHackInfiniteBullets()
            << std::endl;

  std::cout << std::endl;

  std::cout << "> Testing set_god and is_god" << std::endl << std::endl;

  std::cout << "    set_god(true)" << std::endl;
  p.SetHackGod(true);
  std::cout << "        is_god(): " << p.IsHackGod() << std::endl;

  std::cout << "    set_god(false)" << std::endl;
  p.SetHackGod(false);
  std::cout << "        is_god(): " << p.IsHackGod() << std::endl;

  std::cout << std::endl;
}
