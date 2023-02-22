/*
** EPITECH PROJECT, 2023
** Archi
** File description:
** EventComponent
*/

#ifndef EVENTCOMPONENT_HPP_
#define EVENTCOMPONENT_HPP_
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "IComponent.hpp"

namespace rtype {
     enum Action{
            Click,
            Shoot
        };
class EventComponent {
        public:
            EventComponent();
            ~EventComponent();
            struct hitbox{
                int x;
                int y;
                int width;
                int height;
            };
            bool ishooting;
            void eventHandler(sf::RenderWindow& window, sf::Event event, sf::Keyboard::Key key, rtype::Action action, void(*direction)()= NULL);
            typedef struct hitbox hitbox;
        protected:
        private:
            void shoot(sf::RenderWindow& window) const;
    };
}

#endif /* !EVENTCOMPONENT_HPP_ */
