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
    }

    void GraphicSystem::onUpdateSprites(std::vector<Entity *> entities)
    {
        return;
    }

} // namespace rType