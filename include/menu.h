#pragma once
#include <iostream>
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
protected:
    sf::RenderWindow& mWindow;
    EMenuType mMenu_Type;
    bool mVisible;

public:
    CMenu(sf::RenderWindow& Window, EMenuType Menu_Type) : mWindow(Window), mMenu_Type(Menu_Type), mVisible(false) {}
    virtual ~CMenu() = default;

    virtual auto get_visible() const -> bool { return mVisible; };
    virtual auto set_visible(bool value) -> void { mVisible = value; };
    virtual auto draw() -> void = 0;
    virtual auto handle_click_event(CPanel& panel) -> void = 0;

    virtual auto get_menu_name() const -> const EMenuType& { return mMenu_Type; }
};