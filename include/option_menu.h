#pragma once
#include "SFML/Graphics.hpp"
#include "text.h"
#include "menu.h"

class COption_menu : public CMenu
{
private:
	const std::string mPath = "./assets/menus/pause/pause.png";

	CText mTitle_Text;
	CText mBack_Text;

	auto get_text_components() -> std::vector<std::reference_wrapper<CText>>;
	auto set_text_position(sf::RenderWindow& Window) -> void;

public:
	COption_menu(sf::RenderWindow& Window);

	auto render(sf::RenderWindow& Window) -> void override;
	auto handle_events(sf::Event& Event, sf::RenderWindow& Window, CMenuManager& MenuManager, CStateManager* StateManager) -> void override;
};

