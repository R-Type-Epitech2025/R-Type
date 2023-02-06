/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** graphicSystem
*/
#include "GraphicSystem.hpp"
#include <iostream>

namespace rtype {
    namespace system {
        /**
         * @brief Construct a new Graphic System::Graphic System object
         * 
         * @param window 
         */
        GraphicSystem::GraphicSystem(sf::RenderWindow& window)
            : _window(window)
        {
                    std::cout << "Hello World" << std::endl;

        }

        /**
         * @brief Destroy the Graphic System::Graphic System object
         * 
         */
        GraphicSystem::~GraphicSystem()
        {
        }

        /**
         * @brief Update the graphic of the window
         * 
         * @param entities 
         */
        void GraphicSystem::update(std::vector<std::shared_ptr<Entity> >& entities)
        {
            _window.clear();
            for (const auto& entity : entities)
            {
                sf::CircleShape shape(30.f);
                shape.setFillColor(sf::Color::Green);
                shape.setPosition(entity->x, entity->y);

                _window.draw(shape);
            }
            _window.display();
        }
    }
} // namespace rType