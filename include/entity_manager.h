#pragma once
#include <vector>
#include "entity.h"

class CEntityManager
{
private:
	std::vector<std::unique_ptr<CEntity>> mEntity_Vec;
	unsigned int mMax_Entities = 5;

	auto add_entity(std::unique_ptr<CEntity> entity) -> void;
	auto remove_entity(int id) -> void;

public:
	auto prepare_vec(sf::RenderWindow& Window) -> bool;
	auto handle_events(sf::RenderWindow& Window, sf::Event& Event) -> void;
	auto render() -> void;
	auto update(float delta_time) -> void;
};

