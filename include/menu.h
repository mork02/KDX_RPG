#pragma once
#include <iostream>
#include "asset_loader.h"
#include "SFML/Graphics.hpp"

enum class EMenuType
{
    Pause,
    Options,
    Inventory,
    Stats
};

class CGameplay;
class CPanel;

class CMenu : public CAsset_loader
{
private:
    bool mVisible;

protected:
    sf::RenderWindow& mWindow;
    EMenuType mMenu_Type;

public:
    CMenu(sf::RenderWindow& Window, EMenuType Menu_Type) :
        mWindow(Window), mMenu_Type(Menu_Type),
        CAsset_loader(Window),
        mVisible(false) 
    {}
    virtual ~CMenu() = default;

    auto get_visible() const -> bool { return mVisible; };
    auto set_visible(bool value) -> void { mVisible = value; };

    virtual auto draw() -> void = 0;
    virtual auto handle_click_event(CGameplay& Gameplay, CPanel* Panel) -> void = 0;

    auto get_menu_name() -> const EMenuType& { return mMenu_Type; }
};