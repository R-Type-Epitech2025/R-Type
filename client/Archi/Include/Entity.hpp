/*
** EPITECH PROJECT, 2023
** client
** File description:
** Component
*/

#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include "IEntity.hpp"
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "./components/IComponent.hpp"

namespace rtype {
        enum DIRECTION{
            FORWARD,
            BACKWARD,
            TOP,
            BOTTOM,
        };
        enum type {
            BUTTON = 3,
            PLAYER = 2,
            MAIN_PLAYER = 1,
            BACKGROUND = 0,
        };
       struct Containers {
            GameComponent *game_component;
            EventComponent *event_component;
            GraphicComponent *graphic_component;
            MovementComponent *movement_component;
        };
    class Entity {
    public:
        /**
         * @brief Construct a new Entity object
         */
        Entity(rtype::type type);

        /**
         * @brief Destroy the Entity object
         * 
         */
        ~Entity();

        /**
         * @brief Create a Entity object
         * 
         * @return std::vector<Entity> 
         */
        /**
         * @brief 
         * 
         * @return std::vector<Entity>
         * 
         * 
         */

        /**
         * @brief 
         * 
         * 
         * 
         */

        void add_Container(const ComponentType &componentype);
        /**
         * @brief 
         * 
         * 
         */
        void remove_Container(const ComponentType &componentype);
        /**
         * @brief 
         * 
         * 
         */

        void get_containers();

        rtype::DIRECTION get_directions();
        void set_direction(rtype::DIRECTION direction);
        struct Containers container;  // c'est le temps de tester !!!pas du tout definitif;
        rtype::type _type;
        // Load the entity
    protected:
        
    private:
        rtype::DIRECTION direction;
        sf::Vector2f position;
        sf::Texture texture;
};      
};

#endif /* !ENTITY_HPP_ */
