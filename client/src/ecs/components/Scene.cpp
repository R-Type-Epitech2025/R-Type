/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Scene
*/

#include "ecs/Scene.hpp"
#include "ecs/Entity.hpp"
#include <iostream>

rtype::Scene::Scene()
{
    std::cout << "Scene created" << std::endl;
}

rtype::Scene::~Scene()
{
}

void rtype::Scene::addEntity(rtype::Entity *entity){
    _entities.push_back(entity);
}

std::vector<rtype::Entity*> rtype::Scene::get_entity(){
    return(
        _entities
    );
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

