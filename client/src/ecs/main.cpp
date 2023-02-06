/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** main
*/

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include "../../include/systems/GraphicSystem.hpp"
#include "../../include/systems/EventSystem.hpp"
#include "../../include/ecs/Entity.hpp"

/**
 * @brief Main function
 * 
 * @return int 
 */
int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "My Game");

    rtype::system::GraphicSystem graphicsSystem(window);
    rtype::system::EventSystem eventSystem(window);

    std::vector<std::shared_ptr<rtype::Entity> > entities;

    while (window.isOpen())
    {
        eventSystem.update(entities);
        graphicsSystem.update(entities);
    }

    return 0;
}