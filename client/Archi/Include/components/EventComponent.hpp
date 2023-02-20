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

namespace rtype {
     enum Action{
            Click,
            shoot
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
            void eventHandler(sf::Event event, sf::Keyboard::Key key, rtype::Action action, void(*direction)()= NULL);
            typedef struct hitbox hitbox;
        protected:
        private:
    };
}

#endif /* !EVENTCOMPONENT_HPP_ */
