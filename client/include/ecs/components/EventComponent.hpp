/*
** EPITECH PROJECT, 2023
** Archi
** File description:
** EventComponent
*/

#ifndef EVENTCOMPONENT_HPP_
#define EVENTCOMPONENT_HPP_
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

namespace rtype {
    enum EntityType {
            MOB = 5,
            BULLET = 4,
            BUTTON = 3,
            PLAYER = 2,
            MAIN_PLAYER = 1,
            BACKGROUND = 0,
        };
class EventComponent {
        public:
            EventComponent(rtype::EntityType entity);
            ~EventComponent();
            struct hitbox{
                int x;
                int y;
                int width;
                int height;
            };
              bool ishooting;
            void eventHandler(sf::Event event, sf::Keyboard::Key key, sf::RenderWindow &window, void(*direction)()= NULL);
            void setHitbox(int x, int y, int width, int height);
            typedef struct hitbox hitbox;
        protected:
        private:
            hitbox _hitbox;
            bool is_hitbox;
            rtype::EntityType entity;
    };
}

#endif /* !EVENTCOMPONENT_HPP_ */
