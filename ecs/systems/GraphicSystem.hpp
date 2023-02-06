/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** GraphicSystem
*/
#ifndef GRAPHICSYSTEM_HPP
#define GRAPHICSYSTEM_HPP


#include <SFML/Graphics.hpp>
#include "../Entity.hpp"
#include <memory>

namespace rtype {
        class GraphicSystem {
            public:

                /**
                 * @brief Construct a new Graphic System object
                 * 
                 * @param window 
                 */
                GraphicSystem(sf::RenderWindow& window);

                /**
                 * @brief Destroy the Graphic System object
                 * 
                 */
                ~GraphicSystem();

                /**
                 * @brief Update the graphic of the window
                 * 
                 * @param entities 
                 */
                void update(std::vector<std::shared_ptr<rtype::Entity> > & entities);
            protected:
            private:
                sf::RenderWindow& _window;
        };
} // namespace rType

#endif /* !GRAPHICSYSTEM_HPP */
