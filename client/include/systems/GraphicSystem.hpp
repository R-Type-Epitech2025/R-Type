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
    namespace system {
        class GraphicSystem {
            public:
                GraphicSystem(sf::RenderWindow& window);
                ~GraphicSystem();
                void update(std::vector<std::shared_ptr<rtype::Entity> > & entities);
            protected:
            private:
                sf::RenderWindow& _window;
        };
    }
} // namespace rType

#endif /* !GRAPHICSYSTEM_HPP */
