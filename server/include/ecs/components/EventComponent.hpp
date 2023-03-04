/*
** EPITECH PROJECT, 2023
** Archi
** File description:
** EventComponent
*/

#ifndef EVENTCOMPONENT_HPP_
#define EVENTCOMPONENT_HPP_

#include <SFML/Graphics.hpp>
#include <QtNetwork>
#include <iostream>
#include <memory>

namespace rtype {
    /**
     ** @brief Enum of all the entity type
     ** 
     */
    enum EntityType {
            MOB = 5,
            BULLET = 4,
            BUTTON = 3,
            PLAYER = 2,
            MAIN_PLAYER = 1,
            BACKGROUND = 0,
            TEXT = 6,
        };
class EventComponent {
        public:
            /**
             ** @brief Construct a new Event Component object
             ** 
             ** @param entity 
             ** @param positioninscreen 
             ** @param sizeHitbox 
             */
            EventComponent(rtype::EntityType entity, std::vector<int> positioninscreen, std::vector<int> sizeHitbox);

            /**
             ** @brief Destroy the Event Component object
             ** 
             */
            ~EventComponent();

            /**
             ** @brief struct of the hitbox
             ** 
             */
            struct hitbox{
                int x;
                int y;
                int width;
                int height;
            };
            bool ishooting;

            /**
             ** @brief set the hitbox
             ** 
             ** @param x 
             ** @param y 
             ** @param width 
             ** @param height 
             */
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
