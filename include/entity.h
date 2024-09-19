#pragma once

class Entitie
{
private:
    int hp, max_hp;
    int basic_dmg;
    int basic_defensive;

public:
    // Constructor
    Entitie(int HP, int basic_DMG, int basic_DEFENSIVE);

    // Getter
    auto get_hp() const -> int;
    auto get_max_hp() const -> int;
    auto get_basic_dmg() const -> int;
    auto get_basic_defensive() const -> int;

    // Setter
    auto set_hp(int Amount) -> void;
    auto set_max_hp(int Amount) -> void;
    auto set_basic_dmg(int Amount) -> void;
    auto set_basic_defensive(int Amount) -> void;

    // Methods
};
