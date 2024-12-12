#pragma once
#include <iostream>
#include "asset_loader.h"
#include "SFML/Graphics.hpp"
#include "enums.h"

class CMenuManager;
class CStateManager;

class CMenu : public CAsset_loader
{

protected:
    bool mVisible;
    EMenuState mMenu_Type;

public:
    CMenu(sf::RenderWindow& Window, EMenuState Menu_Type) :
        mMenu_Type(Menu_Type),
        CAsset_loader(Window),
        mVisible(false) 
    {}
    virtual ~CMenu() = default;

    auto get_visible() const -> bool { return mVisible; };
    auto set_visible(bool value) -> void { mVisible = value; };

    virtual auto render(sf::RenderWindow& Window) -> void = 0;
    virtual auto handle_events(sf::Event& Event, sf::RenderWindow& Window, CMenuManager& MenuManager, CStateManager* StateManager) -> void = 0;
};