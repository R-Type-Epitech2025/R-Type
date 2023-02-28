/*
** EPITECH PROJECT, 2023
** client
** File description:
** Component
*/

#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include "ecs/components/GraphicComponent.hpp"
#include "ecs/components/EventComponent.hpp"
#include "ecs/components/MovementComponent.hpp"
#include "ecs/components/GameComponent.hpp"

namespace rtype {
         enum EntityType {
            MOB = 5,
            BULLET = 4,
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
          enum ComponentType {
            GAMECOMPONENT = 0,
            GRAPHICCOMPONENT = 1,
            MOVEMENTCOMPONENT = 2,
            EVENTCOMPONENT = 3,
        };
    class Entity {
    public:
        /**
         * @brief Construct a new Entity object
         */
        Entity(rtype::EntityType type);

        /**
         * @brief Destroy the Entity object
         * 
         */
        ~Entity();

        /**
         * @brief 
         * 
         * @param componentype 
         */
        void add_Container(const ComponentType &componentype);
        
        /**
         * @brief 
         * 
         * @param componentype 
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
        rtype::EntityType _type;
        // Load the entity
    protected:
        
    private:
        rtype::DIRECTION direction;
        sf::Vector2f position;
        sf::Texture texture;
};      
};

#endif /* !ENTITY_HPP_ */
