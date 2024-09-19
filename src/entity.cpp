#include "entitie.h"

Entitie::Entitie(int hp_c, int basic_dmg_c, int basic_defensive_c)
    : hp(hp_c), max_hp(hp_c), basic_dmg(basic_dmg_c), basic_defensive(basic_defensive_c) {}

// Getter

auto Entitie::get_hp() const -> int
{
    return hp;
}

auto Entitie::get_max_hp() const -> int
{
    return max_hp;
}

auto Entitie::get_basic_dmg() const -> int
{
    return basic_dmg;
}

auto Entitie::get_basic_defensive() const -> int
{
    return basic_defensive;
}

// Setter

auto Entitie::set_hp(int amount) -> void
{
    hp = hp + amount;
    if (hp > max_hp)
    {
        hp = max_hp;
    }
}

auto Entitie::set_max_hp(int amount) -> void
{
    max_hp = amount;
}

auto Entitie::set_basic_dmg(int amount) -> void
{
    basic_dmg = amount;
}

auto Entitie::set_basic_defensive(int amount) -> void
{
    basic_defensive = amount;
}
