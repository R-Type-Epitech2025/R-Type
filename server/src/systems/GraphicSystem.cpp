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
    void GraphicSystem::update(SceneManager* manager, uint64_t time)
    {
        Scene *scene = manager->getCurrentScene();

        for (auto &entity : scene->get_entities()) {
            if (entity->container.graphic_component->position.x > (1920 + 200) 
            || (entity->container.graphic_component->position.y > (1080 +200)) 
            || (entity->container.graphic_component->position.x < (entity->container.graphic_component->size.width - 200)) 
            || (entity->container.graphic_component->position.x < (entity->container.graphic_component->size.width - 200))) {
                scene->removeEntity(entity);
            }
    }

    void GraphicSystem::onUpdateSprites(std::vector<Entity *> entities)
    {
        return;
    }

} // namespace rType