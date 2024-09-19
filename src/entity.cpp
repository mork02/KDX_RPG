#include "entity.h"

CEntity::CEntity(int hp_c, int basic_dmg_c, int basic_defensive_c)
    : hp(hp_c), max_hp(hp_c), basic_dmg(basic_dmg_c), basic_defensive(basic_defensive_c) {}

// Getter

auto CEntity::get_hp() const -> int
{
    return hp;
}

auto CEntity::get_max_hp() const -> int
{
    return max_hp;
}

auto CEntity::get_basic_dmg() const -> int
{
    return basic_dmg;
}

auto CEntity::get_basic_defensive() const -> int
{
    return basic_defensive;
}

// Setter

auto CEntity::set_hp(int amount) -> void
{
    hp = hp + amount;
    if (hp > max_hp)
    {
        hp = max_hp;
    }
}

auto CEntity::set_max_hp(int amount) -> void
{
    max_hp = amount;
}

auto CEntity::set_basic_dmg(int amount) -> void
{
    basic_dmg = amount;
}

auto CEntity::set_basic_defensive(int amount) -> void
{
    basic_defensive = amount;
}
