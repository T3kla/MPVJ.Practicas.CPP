#include "player.h"

namespace tkl::bit {

// 8 health, 8 bullets, 4 bros, 8 empty, 1 berk, 1 shield, 1 infBullets, 1 god

static BitSpan health = BitSpan(24, 8);
static BitSpan bullets = BitSpan(16, 8);
static BitSpan brothers = BitSpan(12, 4);
static BitSpan berserker = BitSpan(3, 1);
static BitSpan shield = BitSpan(2, 1);
static BitSpan infBullets = BitSpan(1, 1);
static BitSpan god = BitSpan(0, 1);

int Player::GetHealth() const { return Get(data, health); }
void Player::SetHealth(const int &value) { Set(data, health, value); }
// ----------------------------------------- Bullets
int Player::GetBullets() const { return Get(data, bullets); }
void Player::AddBullets(const int &value) {
  int bullets = GetBullets();
  Set(data, bullets, value + bullets);
}

int Player::GetBrothers() const { return Get(data, brothers); }
void Player::GetBrothers(const int &value) { Set(data, brothers, value); }

bool Player::IsBerserker() const { return Get(data, berserker) > 0; }
void Player::SetBerserker(const bool &value) {
  Set(data, berserker, value ? 0b1 : 0b0);
}

bool Player::IsShield() const { return Get(data, shield) > 0; }
void Player::SetShield(const bool &value) {
  Set(data, shield, value ? 0b1 : 0b0);
}

bool Player::IsHackInfiniteBullets() const { return Get(data, infBullets) > 0; }
void Player::SetHackInfiniteBullets(const bool &value) {
  Set(data, infBullets, value ? 0b1 : 0b0);
}

bool Player::IsHackGod() const { return Get(data, god) > 0; }
void Player::SetHackGod(const bool &value) {
  Set(data, god, value ? 0b1 : 0b0);
}

}; // namespace tkl::bit
