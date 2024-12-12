#include "stats_menu.h"

CStats_menu::CStats_menu(sf::RenderWindow& Window) : 
    CMenu(Window, EMenuState::STATS)
{
    init_asset(mPath);
    get_Sprite().setScale(6, 6);
    center_asset(Window);
}

auto CStats_menu::render(sf::RenderWindow& Window) -> void
{

    if (get_visible())
    {
        Window.draw(get_Sprite());
    }
}

auto CStats_menu::handle_events(sf::Event& Event, sf::RenderWindow& Window, CMenuManager& MenuManager, CStateManager* StateManager) -> void
{

}