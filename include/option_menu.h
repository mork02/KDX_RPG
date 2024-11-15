#pragma once
#include "SFML/Graphics.hpp"
#include "text.h"
#include "menu.h"

class CPanel;

class COption_menu : public CMenu
{
private:
	const std::string mPath = "./assets/menus/pause/pause.png";

	CText mTitle_Text;
	CText mBack_Text;

	auto get_text_components() -> std::vector<std::reference_wrapper<CText>>;
	auto set_text_position() -> void;

public:
	COption_menu(sf::RenderWindow& Window);

	auto draw() -> void override;
	auto handle_click_event(CGameplay& Gameplay, CPanel* Panel) -> void override;
};

