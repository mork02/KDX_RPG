#pragma once
#include <iostream>
#include "asset_loader.h"
#include "SFML/Graphics.hpp"
#include "enums.h"

class CGameplay;
class CGameManager;

class CMenu : public CAsset_loader
{
private:
    bool mVisible;

protected:
    sf::RenderWindow& mWindow;
    EMenuState mMenu_Type;

public:
    CMenu(sf::RenderWindow& Window, EMenuState Menu_Type) :
        mWindow(Window), mMenu_Type(Menu_Type),
        CAsset_loader(Window),
        mVisible(false) 
    {}
    virtual ~CMenu() = default;

    auto get_visible() const -> bool { return mVisible; };
    auto set_visible(bool value) -> void { mVisible = value; };

    virtual auto draw() -> void = 0;
    virtual auto handle_events(CGameplay& Gameplay, CGameManager* GameManager) -> void = 0;

    auto get_menu_name() -> const EMenuState& { return mMenu_Type; }
};