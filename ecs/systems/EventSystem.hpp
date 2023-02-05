/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** EventSystem
*/

#ifndef EVENTSYSTEM_HPP_
#define EVENTSYSTEM_HPP_

#include <SFML/Graphics.hpp>
#include "../Entity.hpp"
#include <memory>

namespace rtype {
    class EventSystem {
        public:
        
            EventSystem(sf::RenderWindow& window);
            ~EventSystem();
            void update(std::vector<std::shared_ptr<rtype::Entity> >& entities);

        protected:
        private:
            sf::RenderWindow& _window;
};
}

#endif /* !EVENTSYSTEM_HPP_ */
