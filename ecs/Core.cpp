/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** core
*/

#include "Core.hpp"
#include <SFML/Graphics.hpp>
#include "systems/GraphicSystem.hpp"
#include "systems/EventSystem.hpp"
#include "Entity.hpp"
#include "SceneManager.hpp"


namespace rtype {
    void Core::mainLoop() {
        sf::RenderWindow window(sf::VideoMode(800, 600), "My Game");

        rtype::GraphicSystem graphicsSystem(window);
        rtype::EventSystem eventSystem(window);
        std::vector<std::shared_ptr<rtype::Entity> > entities;

        while (window.isOpen())
        {
            eventSystem.update(entities);
            _sceneManager.update();
            _sceneManager.draw();
            graphicsSystem.update(entities);
        }
    }
}