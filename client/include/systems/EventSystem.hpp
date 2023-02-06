/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** EventSystem
*/

#ifndef EVENTSYSTEM_HPP_
#define EVENTSYSTEM_HPP_

#include <SFML/Graphics.hpp>
#include "../ecs/Entity.hpp"
#include <memory>
#include "../ecs/components/MovementManager.hpp"

namespace rtype {
    namespace system {
        class EventSystem {
            public:
            
                EventSystem(sf::RenderWindow& window);
                ~EventSystem();
                void update(std::vector<std::shared_ptr<rtype::Entity> >& entities);

            protected:
            private:
                sf::RenderWindow& _window;
                rtype::MouvementManager  _mouvement;

        };
    }
}

#endif /* !EVENTSYSTEM_HPP_ */
