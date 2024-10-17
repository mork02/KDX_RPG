#include "gameplay.h"

Gameplay::Gameplay(sf::RenderWindow& Window) :
	mWindow(Window)
{
	mPlayer = std::make_unique<CPlayer>(Window);
	mPlayer2 = std::make_unique<CPlayer>(Window);
	loadLevel();
	loadEntities();
}

auto Gameplay::loadEntities() -> void
{
	mShown_Entities.push_back(mPlayer.get());
	mShown_Entities.push_back(mPlayer2.get());
}

auto Gameplay::loadLevel() -> void
{

}

auto Gameplay::update() -> void
{
	for (auto& entities : mShown_Entities)
	{
		entities->draw();
	}
	mPlayer->set_Position(1, 0);
	mPlayer2->set_Position(0, 1);
}