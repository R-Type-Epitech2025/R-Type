/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** EventSystem
*/

#include "EventSystem.hpp"


rtype::EventSystem::EventSystem(sf::RenderWindow &window ) : _window( window )
{
}

rtype::EventSystem::~EventSystem()
{
}

void rtype::EventSystem::update(std::vector<std::shared_ptr<rtype::Entity>> &entities)
{
    sf::Event event;
    while (_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            _window.close();
        else if (event.type == sf::Event::MouseButtonPressed)
        {
            entities.push_back(std::make_unique<rtype::Entity>());
            auto& newEntity = entities.back();
            newEntity->x = event.mouseButton.x;
            newEntity->y = event.mouseButton.y;
            printf("New entity");
        }
    }
}