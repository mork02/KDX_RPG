#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

enum class EMenuType
{
    Stats,
    Inventory,
    Pause
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

    virtual auto get_menu_name() const -> const EMenuType& { return menuType; }
};