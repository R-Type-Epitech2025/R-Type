/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Scene
*/

#include "Scene.hpp"
#include <iostream>

namespace rtype {
    Scene::Scene()
    {
        _entities = std::vector<rtype::Entity*>();
        std::cout << "Scene created" << std::endl;
    }

    Scene::~Scene()
    {
    }

    void Scene::addEntity(Entity *entity){
        _entities.push_back(entity);
    }

    std::vector<Entity*> Scene::getEntities() {
        return(_entities);
    }

    Entity *Scene::getEntity(quint32 id) {
        for (auto &entity : _entities) {
            if (entity->_id == id)
                return (entity);
        }
        return (nullptr);
    }
}