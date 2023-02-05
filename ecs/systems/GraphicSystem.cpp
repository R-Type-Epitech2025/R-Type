/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** graphicSystem
*/
#include "GraphicSystem.hpp"
#include <iostream>

rtype::GraphicSystem::GraphicSystem(sf::RenderWindow& window)
    : _window(window)
{
            std::cout << "Hello World" << std::endl;

}


rtype::GraphicSystem::~GraphicSystem()
{
}

void rtype::GraphicSystem::update(std::vector<std::shared_ptr<rtype::Entity> >& entities)
{
    _window.clear();
        for (const auto& entity : entities)
        {
            sf::CircleShape shape(100.f);
            shape.setFillColor(sf::Color::Green);
            shape.setPosition(entity->x, entity->y);

            _window.draw(shape);
        }
        _window.display();
    }