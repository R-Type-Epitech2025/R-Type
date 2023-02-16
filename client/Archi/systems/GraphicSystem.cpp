/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** graphicSystem
*/
#include "../Include/systems/GraphicSystem.hpp"
#include <iostream>
#include <string>

namespace rtype {
        /**
         * @brief Construct a new Graphic System::Graphic System object
         * 
         * @param window 
         */
        GraphicSystem::GraphicSystem()
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
        // void GraphicSystem::update(std::vector<Entity *> >& entities)
        // {
        //     _window.clear();
        //     for (const auto& entity : entities)
        //     {
        //         sf::CircleShape shape(30.f);
        //         if (entity->color == "blue"){
        //             shape.setFillColor(sf::Color::Blue);
        //         } else if (entity->color == "red") {
        //             shape.setFillColor(sf::Color::Red);
        //         }
        //         shape.setPosition(entity->x, entity->y);

        //         _window.draw(shape);
        //     }
        //     _window.display();
        // }
} // namespace rType