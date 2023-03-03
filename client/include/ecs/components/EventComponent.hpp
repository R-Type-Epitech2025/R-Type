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

    /**
     * @brief Enum of all the entity type
     * 
     */
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

            /**
             * @brief Construct a new Event Component object
             * 
             * @param entity 
             * @param positioninscreen 
             * @param sizeScreen 
             */
            EventComponent(rtype::EntityType entity, std::vector<int> positioninscreen, std::vector<int> sizeScreen);

            /**
             * @brief Destroy the Event Component object
             * 
             */
            ~EventComponent();

            /**
             * @brief struct of the hitbox
             * 
             */
            struct hitbox{
                int x;
                int y;
                int width;
                int height;
            };
            
            /**
             * @brief event handler / help to change the scene and return true if the event is triggered
             * 
             * @param event 
             * @param key 
             * @param window 
             * @return true 
             * @return false 
             */
            bool eventHandler(sf::Event event, sf::Keyboard::Key key, sf::RenderWindow &window);

            // void eventHandler(sf::Event event, sf::Mouse::Button key, sf::RenderWindow &window, void(*direction)() = NULL);

            /**
             * @brief Set the Hitbox object
             * 
             * @param x 
             * @param y 
             * @param width 
             * @param height 
             */
            void setHitbox(int x, int y, int width, int height);

            typedef struct hitbox hitbox;

            bool ishooting;
        protected:
        private:
            hitbox _hitbox;
            bool is_hitbox;
            rtype::EntityType entity;
    };

    EntityType convertUint32ToEntityType(uint32_t type);

}

#endif /* !EVENTCOMPONENT_HPP_ */
