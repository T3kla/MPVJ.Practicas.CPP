#pragma once

#include "..\bit_magic\bit_magic.h"
#include <iostream>

namespace player {

struct player;
struct data;

struct player {
public:
  std::unique_ptr<data> save_data;
  player();
};

struct data {
private:
  int m_data = 0;

  // 8 health, 8 bullets, 4 bros, 8 empty, 1 berk, 1 shield, 1 infBullets, 1 god
  tkl::BitSpan m_health = tkl::BitSpan(24, 8);
  tkl::BitSpan m_bullets = tkl::BitSpan(16, 8);
  tkl::BitSpan m_brothers = tkl::BitSpan(12, 4);
  tkl::BitSpan m_berserker = tkl::BitSpan(3, 1);
  tkl::BitSpan m_shield = tkl::BitSpan(2, 1);
  tkl::BitSpan m_infBullets = tkl::BitSpan(1, 1);
  tkl::BitSpan m_god = tkl::BitSpan(0, 1);

public:
  // ----------------------------------------- Health
  int get_health() const;
  void set_health(const int &value);

  // ----------------------------------------- Bullets
  int get_bullets() const;
  void add_bullets(const int &value);

  // ----------------------------------------- Brothers
  int get_brothers() const;
  void set_brothers(const int &value);

  // ----------------------------------------- Berserker
  bool is_berserker() const;
  void set_berserker(const bool &value);

  // ----------------------------------------- Shield
  bool is_shield() const;
  void set_shield(const bool &value);

  // ----------------------------------------- Infinite Bullet Hack
  bool is_infBullets() const;
  void set_infBullets(const bool &value);

  // ----------------------------------------- God
  bool is_god() const;
  void set_god(const bool &value);
};

} // namespace player
