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
        std::cout << "Hello World" << std::endl;
    }

    // GraphicSystem::~GraphicSystem()
    // {
    // }

    void GraphicSystem::update(rtype::SceneManager* manager, uint64_t time)
    {
        Scene *scene = manager->getCurrentScene();
        // int i = 0;
        // int save = 0;

        for (const Entity *entity : scene->get_entities())
        {
            if (entity->container.movement_component != NULL && entity->container.movement_component->velocity.x != 0) {
                entity->container.graphic_component->setPosition(entity->container.movement_component->pos.x, entity->container.movement_component->pos.y);
                if (entity->container.graphic_component->counter_sprites != 0) {
                    int current_sprite_index = (time/400) % entity->container.graphic_component->counter_sprites;
                    entity->container.graphic_component->setSpritePosition(current_sprite_index * entity->container.graphic_component->size.width, entity->container.graphic_component->position.sprite_y);
                }
            }
            // save = entity->container.graphic_component->position.sprite_x;
            // entity->container.graphic_component->setSpritePosition(entity->container.graphic_component->position.sprite_x, entity->container.graphic_component->position.sprite_y);
            manager->window.draw(entity->container.graphic_component->getSprite());
        }
        manager->window.display();
        manager->window.clear();
    }

    void GraphicSystem::init(rtype::SceneManager &Manager, sf::RenderWindow &window)
    {
    }

    void GraphicSystem::onUpdateEntities(std::vector<Entity *> entities)
    {
        return;
    }

} // namespace rType