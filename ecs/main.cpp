/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** main
*/

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include "systems/GraphicSystem.hpp"
#include "systems/EventSystem.hpp"
#include "Entity.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "My Game");

    rtype::GraphicSystem graphicsSystem(window);
    rtype::EventSystem eventSystem(window);

    std::vector<std::shared_ptr<rtype::Entity>> entities;

    while (window.isOpen())
    {
        eventSystem.update(entities);
        graphicsSystem.update(entities);
    }

    return 0;
}