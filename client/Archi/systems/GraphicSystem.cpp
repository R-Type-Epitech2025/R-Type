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
        void GraphicSystem::Update(SceneManager* Manager, int deltaTime, sf::RenderWindow &window)
        {
            Scene *scene = Manager->getCurrentScene();

            for (const auto& entity : scene->get_entity())
            {
                entity->container.graphic_component->setPosition(entity->container.movement_component->pos.x, entity->container.movement_component->pos.y);
                window.draw(entity->container.graphic_component->getSprite());
            }
            window.display();
        }
} // namespace rType