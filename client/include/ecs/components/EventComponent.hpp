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
        BACKGROUND = 0,
        MAIN_PLAYER,
        PLAYER,
        BUTTON,
        BULLET,
        MOB,
        TEXT
    };

    /**
    ** @brief struct of the hitbox
    ** 
    */
    typedef struct hitbox{
        int x;
        int y;
        int width;
        int height;
    }hitbox_t;

    /**
    ** @brief struct that contains all the information about the event
    ** 
    */
    typedef struct NewEvent{
        quint32 entityId;
        std::string futureSceneName;
        std::string currentSceneName;
    } NewEvent_t;
    class EventComponent {
        public:

            /**
             ** @brief Construct a new Event Component object
             ** 
             ** @param entity 
             ** @param positioninscreen 
             ** @param sizeScreen 
             */
            EventComponent(EntityType entity, std::vector<int> positioninscreen, std::vector<int> sizeScreen);

            /**
             ** @brief Destroy the Event Component object
             ** 
             */
            ~EventComponent();
            
            /**
             ** @brief event handler / help to change the scene and return true if the event is triggered
             ** 
             ** @param event 
             ** @param window 
             ** @return true 
             ** @return false 
             */
            bool eventHandler(sf::Event event, sf::RenderWindow &window);

            // void eventHandler(sf::Event event, sf::Mouse::Button key, sf::RenderWindow &window, void(*direction)() = NULL);

            /**
             ** @brief Set the Hitbox object
             ** 
             ** @param x 
             ** @param y 
             ** @param width 
             ** @param height 
             */
            void setHitbox(int x, int y, int width, int height);


            /**
             ** @brief Get the Hitbox object
             ** 
             ** @return hitbox 
             */
            hitbox getHitbox() const;

            bool ishooting;
        protected:
        private:
            hitbox _hitbox;
            bool is_hitbox;
            EntityType entity;
    };

    EntityType convertUint32ToEntityType(uint32_t type);

}

#endif /* !EVENTCOMPONENT_HPP_ */
