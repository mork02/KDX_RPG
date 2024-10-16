#pragma once
#include <iostream>

class CEntity
{
private:
    std::string name;
    unsigned id;
    int hp, max_hp;
    int basic_dmg;
    int basic_defensive;

public:
    // Constructor
    CEntity(std::string cName, int cHP, int cMax_HP, int cBasic_Dmg, int cBasic_Defensive)
        : name(cName), hp(cHP), max_hp(cMax_HP), basic_dmg(cBasic_Dmg), basic_defensive(cBasic_Defensive) {}
    virtual ~CEntity() = default;

    // Getter
    virtual auto get_name() const -> std::string { return name; }
    virtual auto get_id() const -> unsigned { return id; }
    virtual auto get_hp() const -> int { return hp; }
    virtual auto get_max_hp() const -> int { return max_hp; }
    virtual auto get_basic_dmg() const -> int { return basic_dmg; }
    virtual auto get_basic_defensive() const -> int { return basic_defensive; }

    // Setter
    virtual auto set_name(std::string Name) -> void { name = Name; }
    virtual auto set_hp(int Amount) -> void { hp = Amount; }
    virtual auto set_max_hp(int Amount) -> void { max_hp = Amount; }
    virtual auto set_basic_dmg(int Amount) -> void { basic_dmg = Amount; }
    virtual auto set_basic_defensive(int Amount) -> void { basic_defensive = Amount; }
};
