/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Scene
*/

#include "Scene.hpp"

rtype::Scene::Scene()
{
}

rtype::Scene::~Scene()
{
}

// void update(Entity& entity, sf::RenderWindow& window) {
//         sf::Sprite sprite(entity.texture);
//         sprite.setPosition(entity.position);
//         window.draw(sprite);
// }

void rtype::Scene::draw(sf::RenderWindow& window)
{
    for (auto& entity : entities) {
        sf::Sprite sprite(entity.texture);
        sprite.setPosition(entity.position);
        window.draw(sprite);
    }
}

void rtype::getScene(std::vector<IScene> scene)
{
    // for (auto& entity : entities) {
    //     sf::Sprite sprite(entity.texture);
    //     sprite.setPosition(entity.position);
    //     window.draw(sprite);
    // }
}

