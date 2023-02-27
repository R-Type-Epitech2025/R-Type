/*
** EPITECH PROJECT, 2023
** Archi
** File description:
** EventComponent
*/

#ifndef EVENTCOMPONENT_HPP_
#define EVENTCOMPONENT_HPP_
#include <SFML/Graphics.hpp>

namespace rtype {
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
            void eventHandler(sf::Event event, sf::Keyboard::Key key, void(*direction)()= NULL);
            typedef struct hitbox hitbox;
        protected:
        private:
    };
}

#endif /* !EVENTCOMPONENT_HPP_ */
