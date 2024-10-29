#pragma once
#include <iostream>
#include "asset_loader.h"
#include "SFML/Graphics.hpp"

class CPanel;

enum class EMenuType
{
    Pause,
    Options,
    Inventory,
    Stats
};

class CMenu
{
private:
    bool mVisible;

protected:
    sf::RenderWindow& mWindow;
    CAsset_loader mAsset;
    EMenuType mMenu_Type;

public:
    CMenu(sf::RenderWindow& Window, EMenuType Menu_Type) :
        mWindow(Window), mMenu_Type(Menu_Type),
        mAsset(Window),
        mVisible(false) 
    {
    // TODO: add the whole render asset / asset_Loader into here, beacuase every menu has a asset/png
    }
    virtual ~CMenu() = default;

    auto get_visible() const -> bool { return mVisible; };
    
    auto set_visible(bool value) -> void { mVisible = value; };

    virtual auto draw() -> void = 0;
    virtual auto handle_click_event(CPanel& panel) -> void = 0;

    auto get_menu_name() const -> const EMenuType& { return mMenu_Type; }
};