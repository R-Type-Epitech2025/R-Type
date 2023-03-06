/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** graphicSystem
*/

#include "GraphicSystem.hpp"
#include <iostream>
#include <string>

namespace rtype {

    GraphicSystem::GraphicSystem(QObject *parent) : QObject(parent)
    {
    }

    GraphicSystem::~GraphicSystem()
    {
    }

    void GraphicSystem::update(SceneManager* manager, uint64_t time)
    {
        Scene *scene = manager->getCurrentScene();
        
        for (const Entity *entity : scene->get_entities())
        {
            if (entity->container.movement_component != nullptr) {
                entity->container.graphic_component->setPosition(entity->container.movement_component->pos.x, entity->container.movement_component->pos.y);
            }
            entity->container.graphic_component->setSpritePosition(entity->container.graphic_component->position.sprite_x, entity->container.graphic_component->position.sprite_y);
            if (entity->_type == EntityType::TEXT)
                manager->window.draw(entity->container.graphic_component->getText());
            else
                manager->window.draw(entity->container.graphic_component->getSprite());
        }
        manager->window.display();
        manager->window.clear();
    }

    void GraphicSystem::init(SceneManager &manager, sf::RenderWindow &window)
    {
    }

    void GraphicSystem::onUpdateEntities(std::vector<EntityCreator_t *> entities)
    {
        emit updateEntities(entities);
    }

} // namespace rType