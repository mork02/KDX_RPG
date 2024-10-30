#pragma once
#include <iostream>
#include "asset_loader.h"
#include "input.h"

class CEntity
{
protected:
    std::string mName;
    // unsigned mID;
    int mHP, mMax_HP;
    int mBasic_DMG;
    int mBasic_DEF;

    CAsset_loader mAsset;

public:
    CEntity(sf::RenderWindow& Window, std::string Name, int HP, int Max_HP, int Basic_DMG, int Basic_DEF)
        : 
        mAsset(Window),
        mName(Name),
        mHP(HP), mMax_HP(Max_HP),
        mBasic_DMG(Basic_DMG), mBasic_DEF(Basic_DEF)
    {}

    virtual ~CEntity() = default;

    auto get_name() const -> std::string { return mName; }
    // virtual auto get_id() const -> unsigned { return mID; }
    auto get_hp() const -> int { return mHP; }
    auto get_max_hp() const -> int { return mMax_HP; }
    auto get_basic_dmg() const -> int { return mBasic_DMG; }
    auto get_basic_defensive() const -> int { return mBasic_DEF; }
    auto get_Asset() const -> CAsset_loader { return mAsset; }

    auto set_name(std::string Name) -> void { mName = Name; }
    auto set_hp(int HP) -> void { mHP = HP; }
    auto set_max_hp(int Max_HP) -> void { mMax_HP = Max_HP; }
    auto set_basic_dmg(int Basic_DMG) -> void { mBasic_DMG = Basic_DMG; }
    auto set_basic_defensive(int Basic_DEF) -> void { mBasic_DEF = Basic_DEF; }

    auto take_damage(int Basic_DMG) -> void 
    {
        int reduced_damage = Basic_DMG - mBasic_DEF;
        if (reduced_damage < 0) reduced_damage = 0;
        mHP -= reduced_damage;
        if (mHP < 0) mHP = 0;
    }
    auto heal(int HP) -> void 
    {
        mHP += HP;
        if (mHP > mMax_HP) mHP = mMax_HP;
    }
    virtual auto handle_movement(float delta_time, CInput& Input) -> void {}
};
