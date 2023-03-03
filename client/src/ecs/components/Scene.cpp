/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Scene
*/

#include "ecs/Scene.hpp"
#include <iostream>


namespace rtype {
    Scene::Scene()
    {
        std::cout << "Scene created" << std::endl;
    }

    Scene::~Scene()
    {
    }

    void Scene::addEntity(rtype::Entity *entity)
    {
        _entities.push_back(entity);
        //std::sort(_entities.begin(), _entities.end());
    }

    std::vector<rtype::Entity*> Scene::get_entities(){
        return(_entities);
    }

    rtype::Entity *Scene::getEntity(std::string id) {
        for (auto &entity : _entities) {
            if (entity->_id == id)
                return (entity);
        }
        return (nullptr);
    }

    void Scene::removeEntity(rtype::Entity *entity)
    {
        for (auto it = _entities.begin(); it != _entities.end(); it++) {
            if (*it == entity) {
                _entities.erase(it);
                break;
            }
        }
    }
}

// void update(Entity& entity, sf::RenderWindow& window) {
//         sf::Sprite sprite(entity.texture);
//         sprite.setPosition(entity.position);
//         window.draw(sprite);
// }

// void rtype::Scene::draw(sf::RenderWindow& window)
// {
// //    for (auto& entity : entities) {
// //         sf::Sprite sprite(entity.texture);
// //         sprite.setPosition(entity.position);
// //         window.draw(sprite);
// //     }
// }

// void rtype::Scene::getScene(std::vector<IScene> scene)
// {
//     // for (auto& entity : entities) {
//     //     sf::Sprite sprite(entity.texture);
//     //     sprite.setPosition(entity.position);
//     //     window.draw(sprite);
//     // }
// }

