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

namespace rtype {
        struct Containers {
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
        Entity(rtype::EntityType type, std::vector<int> positioninscreen, std::vector<int> positioninsprite_sheet , std::vector<int> sizespritesheet, float scale, std::string sprite, std::string id);

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
//        void remove_Container(const ComponentType &componentype);

        /**
         * @brief 
         * 
         * 
         */
//        void get_containers();

        rtype::DIRECTION get_directions();
        void set_direction(rtype::DIRECTION direction);
        struct Containers container;  // c'est le temps de tester !!!pas du tout definitif;
        rtype::EntityType _type;
        std::string _id;
        // Load the entity
    protected:
        
    private:
        rtype::DIRECTION direction;
        sf::Vector2f position;
        sf::Texture texture;
};      

// bool operator>(Entity& os, const Entity& dt)
// {
//     return os._type < os._type;
// }

};

static bool operator<(rtype::Entity& os, const rtype::Entity& dt)
{
    return os._type < os._type;
}

static bool operator>(rtype::Entity& os, const rtype::Entity& dt)
{
    return os._type > os._type;
}


#endif /* !ENTITY_HPP_ */
