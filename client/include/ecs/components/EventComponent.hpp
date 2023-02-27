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
            Shoot,
        };
          struct hitbox{
                int x;
                int y;
                int width;
                int height;
            };
            typedef struct hitbox hitbox;
class EventComponent {
        public:
            EventComponent();
            ~EventComponent();
            bool ishooting;
            void eventHandler(sf::Event event, sf::Keyboard::Key key, rtype::Action action, sf::RenderWindow &window, void(*direction)()= NULL);
            void eventHandler(sf::Event event, sf::Mouse::Button key, rtype::Action action, sf::RenderWindow &window, void(*direction)());
            void setHitbox(int x, int y, int width, int height);

        protected:
        private:
            rtype::hitbox _hitbox;
            bool is_hitbox;
    };
}

#endif /* !EVENTCOMPONENT_HPP_ */
