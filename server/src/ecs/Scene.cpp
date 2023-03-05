/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Scene
*/

#include "ecs/Scene.hpp"
#include <iostream>

rtype::Scene::Scene()
{
    _entities = std::vector<rtype::Entity*>();
    std::cout << "Scene created" << std::endl;
}

rtype::Scene::~Scene()
{
}

void rtype::Scene::addEntity(rtype::Entity *entity){
    _entities.push_back(entity);
    //std::sort(_entities.begin(), _entities.end());
}

std::vector<rtype::Entity*> rtype::Scene::getEntities() {
    return(_entities);
}

rtype::Entity *rtype::Scene::getEntity(quint32 id) {
    for (auto &entity : _entities) {
        if (entity->_id == id)
            return (entity);
    }
    return (nullptr);
}