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
        std::cout << "Scene created" << std::endl;
    }

    Scene::~Scene()
    {
    }

    void Scene::addEntity(Entity *entity){
        _entities.push_back(entity);
        //std::sort(_entities.begin(), _entities.end());
    }

    std::vector<Entity*> Scene::get_entities(){
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