#pragma once

#include "bit.h"
#include <iostream>

namespace tkl::bit {

class Player {
private:
  int data = 0;

public:
  int GetHealth() const;
  void SetHealth(const int &value);

  int GetBullets() const;
  void AddBullets(const int &value);

  int GetBrothers() const;
  void GetBrothers(const int &value);

  bool IsBerserker() const;
  void SetBerserker(const bool &value);

  bool IsShield() const;
  void SetShield(const bool &value);

  bool IsHackInfiniteBullets() const;
  void SetHackInfiniteBullets(const bool &value);

  bool IsHackGod() const;
  void SetHackGod(const bool &value);
};

} // namespace tkl::bit
