#include "player.h"

namespace player
{

player::player() : save_data(std::make_unique<data>())
{
}

// ----------------------------------------- Health

int data::get_health() const
{
    return get(m_data, m_health);
}

void data::set_health(const int &value)
{
    set(m_data, m_health, value);
}

// ----------------------------------------- Bullets

int data::get_bullets() const
{
    return get(m_data, m_bullets);
}

void data::add_bullets(const int &value)
{
    int bullets = get_bullets();
    set(m_data, m_bullets, value + bullets);
}

// ----------------------------------------- Brothers

int data::get_brothers() const
{
    return get(m_data, m_brothers);
}

void data::set_brothers(const int &value)
{
    set(m_data, m_brothers, value);
}

// ----------------------------------------- Berserker

bool data::is_berserker() const
{
    return get(m_data, m_berserker) > 0;
}

void data::set_berserker(const bool &value)
{
    set(m_data, m_berserker, value ? 0b1 : 0b0);
}

// ----------------------------------------- Shield

bool data::is_shield() const
{
    return get(m_data, m_shield) > 0;
}

void data::set_shield(const bool &value)
{
    set(m_data, m_shield, value ? 0b1 : 0b0);
}

// ----------------------------------------- Infinite Bullet Hack

bool data::is_infBullets() const
{
    return get(m_data, m_infBullets) > 0;
}

void data::set_infBullets(const bool &value)
{
    set(m_data, m_infBullets, value ? 0b1 : 0b0);
}

// ----------------------------------------- God

bool data::is_god() const
{
    return get(m_data, m_god) > 0;
}

void data::set_god(const bool &value)
{
    set(m_data, m_god, value ? 0b1 : 0b0);
}

}; // namespace player
