#pragma once
#include <iostream>
#include "asset_loader.h"

class CEntity : public CAsset_loader
{
private:
    std::string mName;
    unsigned mID;
    int mHP, mMax_HP;
    int mBasic_DMG;
    int mBasic_DEF;

public:
    CEntity(sf::RenderWindow& Window, const std::string& Path, bool IsAnimated, bool Debug_Mode, std::string Name, int HP, int Max_HP, int Basic_DMG, int Basic_DEF)
        : CAsset_loader(Window, Path, IsAnimated, Debug_Mode),
        mName(Name),
        mHP(HP), mMax_HP(Max_HP),
        mBasic_DMG(Basic_DMG), mBasic_DEF(Basic_DEF)
    {}
    virtual ~CEntity() = default;

    virtual auto get_name() const -> std::string { return mName; }
    virtual auto get_id() const -> unsigned { return mID; }
    virtual auto get_hp() const -> int { return mHP; }
    virtual auto get_max_hp() const -> int { return mMax_HP; }
    virtual auto get_basic_dmg() const -> int { return mBasic_DMG; }
    virtual auto get_basic_defensive() const -> int { return mBasic_DEF; }

    virtual auto set_name(std::string Name) -> void { mName = Name; }
    virtual auto set_hp(int HP) -> void { mHP = HP; }
    virtual auto set_max_hp(int Max_HP) -> void { mMax_HP = mMax_HP; }
    virtual auto set_basic_dmg(int Basic_DMG) -> void { mBasic_DMG = Basic_DMG; }
    virtual auto set_basic_defensive(int Basic_DEF) -> void { mBasic_DEF = Basic_DEF; }

    virtual auto take_damage(int Basic_DMG) -> void 
    {
        int reduced_damage = Basic_DMG - mBasic_DEF;
        if (reduced_damage < 0) reduced_damage = 0;
        mHP -= reduced_damage;
        if (mHP < 0) mHP = 0;
    }
    virtual auto heal(int HP) -> void 
    {
        mHP += HP;
        if (mHP > mMax_HP) mHP = mMax_HP;
    }
};
