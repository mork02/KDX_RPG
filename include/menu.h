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
    sf::RenderWindow& window;
    EMenuType menuType;
    bool visible;

public:
    CMenu(sf::RenderWindow& window_c, EMenuType menuType_c) : window(window_c), menuType(menuType_c), visible(false) {}
    virtual ~CMenu() = default;

    virtual auto get_visible() const -> bool { return visible; };
    virtual auto set_visible(bool value) -> void { visible = value; };
    virtual auto draw() -> void = 0;
    virtual auto handle_click_event(CPanel& panel) -> void = 0;

    virtual auto get_menu_name() const -> const EMenuType& { return menuType; }
};