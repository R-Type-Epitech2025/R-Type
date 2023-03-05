/*
** EPITECH PROJECT, 2023
** client
** File description:
** Component
*/

#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include "GraphicComponent.hpp"
#include "EventComponent.hpp"
#include "MovementComponent.hpp"

namespace rtype {

    /**
     ** @brief struct that contains all the components of an entity
     ** 
     */
    struct Containers {
        EventComponent *event_component;
        GraphicComponent *graphic_component;
        MovementComponent *movement_component;
    };
    /**
     ** @brief enum that contains all the types of entities
     *
     */
    enum ComponentType {
        GAMECOMPONENT = 0,
        GRAPHICCOMPONENT = 1,
        MOVEMENTCOMPONENT = 2,
        EVENTCOMPONENT = 3,
    };
    class Entity {
    public:
        /**
         ** @brief Construct a new Entity object
         */
        Entity(EntityType type, std::vector<int> positioninscreen, std::vector<int> positioninsprite_sheet , std::vector<int> sizespritesheet, float scale, std::string sprite, uint32_t id, bool isPrint, std::vector<int> velocity = {0, 0});

        /**
         ** @brief Construct a new Entity object
         */
        Entity(EntityType type, std::vector<int> positionInScreen, u_int32_t fontSize, sf::Color& textColor, uint32_t id, bool isPrint);
        
        /**
         ** @brief Destroystd::string text, the Entity object
         ** 
         */
        ~Entity();
        
        /**
         ** @brief get the direction of the entity
         ** 
         ** @return EntityType 
         */
        DIRECTION get_directions();

        /**
         ** @brief set the direction of the entity
         ** 
         ** @return sf::Vector2f 
         */
        void set_direction(DIRECTION direction);

        /**
         ** @brief declaration of container struct
         ** 
         ** @return sf::Vector2f 
         */
        struct Containers container;  // c'est le temps de tester !!!pas du tout definitif;

        EntityType _type;
        quint32 _id;
        // Load the entity
    protected:
        
    private:
        DIRECTION direction;
        sf::Vector2f position;
        sf::Texture texture;
};      

// bool operator>(Entity& os, const Entity& dt)
// {
//     return os._type < os._type;
// }

    static bool operator<(Entity& os, const Entity& dt)
    {
        return os._type < os._type;
    }
    
    static bool operator>(Entity& os, const Entity& dt)
    {
        return os._type > os._type;
    }

};


#endif /* !ENTITY_HPP_ */
