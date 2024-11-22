#pragma once
#include "asset_loader.h"

class CEntity;

class CStatusBar
{
private:
	CAsset_loader mAsset;

public:
	CStatusBar(sf::RenderWindow& Window);
	auto update(CEntity* entity) -> void;
	auto render() -> void;
};

