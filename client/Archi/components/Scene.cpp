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

void update(Entity& entity, sf::RenderWindow& window) {
        sf::Sprite sprite(entity.texture);
        sprite.setPosition(entity.position);
        window.draw(sprite);
}

