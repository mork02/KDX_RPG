#include "entity_manager.h"
#include "player.h"

auto CEntityManager::prepare_vec(sf::RenderWindow& Window) -> bool
{
    mEntity_Vec.reserve(mMax_Entities);
    add_entity(std::make_unique<CPlayer>(Window));
    return true;
}

auto CEntityManager::add_entity(std::unique_ptr<CEntity> entity) -> void
{
    mEntity_Vec.push_back(std::move(entity));
}

auto CEntityManager::remove_entity(int id) -> void {
    auto it = std::find_if(mEntity_Vec.begin(), mEntity_Vec.end(), [id](const std::unique_ptr<CEntity>& entity) 
        {
        return entity->get_id() == id;
        });

    if (it != mEntity_Vec.end()) 
    {
        mEntity_Vec.erase(it);
        std::cout << "Entity with ID " << id << " removed." << std::endl;
    }
    else 
    {
        std::cout << "Entity with ID " << id << " not found." << std::endl;
    }
}

auto CEntityManager::handle_events(sf::RenderWindow& Window, sf::Event& Event) -> void
{
    for (auto& entity : mEntity_Vec)
    {
        entity->handle_events(Window, Event);
    }
}

auto CEntityManager::render() -> void
{
    for (auto& entity : mEntity_Vec)
    {
        entity->render();
    }
}

auto CEntityManager::update(float delta_time) -> void
{
    for (auto& entity : mEntity_Vec)
    {
        entity->update(delta_time);
    }
}




