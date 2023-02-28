/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Entity
*/

#include "ecs/Entity.hpp"


rtype::Entity::Entity(rtype::EntityType type)
{
    this->container.event_component = NULL;
    this->container.game_component = NULL;
    this->container.graphic_component = NULL;
    this->container.movement_component = NULL;
    // this->direction = rtype::DIRECTION::FORWARD;
    this->_type = type;
}


void rtype::Entity::add_Container(const ComponentType &componentype){
    switch (componentype){
        case ComponentType::GAMECOMPONENT: 
            this->container.game_component = new GameComponent();
            break;
        case ComponentType::GRAPHICCOMPONENT:
            this->container.graphic_component = new GraphicComponent();
            break;
        case ComponentType::MOVEMENTCOMPONENT:
            this->container.movement_component = new MovementComponent();
            if (_type == rtype::EntityType::MAIN_PLAYER)
                this->container.movement_component->LinktoKeybord(true);
            break;
        case ComponentType::EVENTCOMPONENT:
            this->container.event_component = new EventComponent();
            break;
    }
}

    rtype::DIRECTION rtype::Entity::get_directions(){
        return direction;
    }

    void rtype::Entity::set_direction(rtype::DIRECTION direction )  {
        this->direction = direction;
    }
    rtype::Entity::~Entity()
    {
    }
