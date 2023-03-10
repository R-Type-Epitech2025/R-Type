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
#include "GameComponent.hpp"

namespace rtype {
        /**
         ** @brief struct for the containers
         ** 
         */
        struct Containers {
            GameComponent *game_component;
            EventComponent *event_component;
            GraphicComponent *graphic_component;
            MovementComponent *movement_component;
        };
        /**
         ** @brief enum of different component type
         ** 
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
        Entity(EntityType type, std::vector<int> positioninscreen, std::vector<int> positioninsprite_sheet , std::vector<int> sizespritesheet, float scale, std::string sprite, quint32 id = 0);

        /**
         ** @brief Construct a new Entity object by copy
         ** 
         ** @param other 
         */
        Entity(Entity& other, quint32 id);

        /**
         ** @brief Destroy the Entity object
         ** 
         */
        ~Entity();

        /**
         ** @brief remove a container
         ** 
         ** @param componentype 
         */
        void remove_Container(const ComponentType &componentype);

        /**
         ** @brief get the container
         ** 
         ** 
         */
        void get_containers();

        /**
         ** @brief Get the directions object
         ** 
         ** @return DIRECTION 
         */
        DIRECTION get_directions();

        /**
         ** @brief Set the direction object
         ** 
         ** @param direction 
         */
        void set_direction(DIRECTION direction);

        /**
         ** @brief Get the position object
         ** 
         ** @return sf::Vector2f 
         */
        quint32 getId() const;

        /**
         ** @brief Get the Entity Type object
         ** 
         ** @return quint32 
         */
        quint32 getEntityType() const;


        /**
         ** @brief Get the Spritesheet Index object
         ** 
         ** @return quint32 
         */
        quint32 getSpritesheetIndex() const;

        /**
         ** @brief Get the Sheet Position object
         ** 
         ** @return std::vector<quint32> 
         */
        std::vector<quint32> getSheetPosition() const;

        /**
         ** @brief Get the Sheet Size object
         ** 
         ** @return std::vector<quint32> 
         */
        std::vector<quint32> getSheetSize() const;


        /**
         ** @brief Get the Scale object
         ** 
         ** @return quint32 
         */
        quint32 getScale() const;

        /**
         ** @brief Get the Position object
         ** 
         ** @return std::vector<quint32> 
         */
        std::vector<quint32> getPosition() const; 


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
