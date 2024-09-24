#pragma once

class CEntity
{
private:
    unsigned id;
    int hp, max_hp;
    int basic_dmg;
    int basic_defensive;

public:
    // Constructor
    CEntity(unsigned id, int hp_c, int max_HP_c, int basic_DMG_c, int basic_DEFENSIVE_c)
        : hp(hp_c), max_hp(max_HP_c), basic_dmg(basic_DMG_c), basic_defensive(basic_DEFENSIVE_c) {}
    virtual ~CEntity() = default;

    // Getter
    virtual auto get_id() const -> unsigned { return id; }
    virtual auto get_hp() const -> int { return hp; }
    virtual auto get_max_hp() const -> int { return max_hp; }
    virtual auto get_basic_dmg() const -> int { return basic_dmg; }
    virtual auto get_basic_defensive() const -> int { return basic_defensive; }

    // Setter
    virtual auto set_hp(int Amount) -> void { hp = Amount; }
    virtual auto set_max_hp(int Amount) -> void { max_hp = Amount; }
    virtual auto set_basic_dmg(int Amount) -> void { basic_dmg = Amount; }
    virtual auto set_basic_defensive(int Amount) -> void { basic_defensive = Amount; }
};
