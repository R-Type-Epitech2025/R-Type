/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Entity
*/

#include "ecs/Entity.hpp"


rtype::Entity::Entity(rtype::EntityType type, int x, int y, int width, int height, std::string sprite)
{
    this->container.event_component = NULL;
    this->container.game_component = NULL;
    this->container.graphic_component = NULL;
    this->container.movement_component = NULL;

    if (type == rtype::EntityType::MAIN_PLAYER){
        this->container.event_component = new EventComponent();
        this->container.graphic_component = new GraphicComponent();
        this->container.movement_component = new MovementComponent();
        this->container.game_component = new GameComponent();
        this->container.movement_component->LinktoKeybord(true);
    } else {
        this->container.event_component = new EventComponent();
        this->container.graphic_component = new GraphicComponent();
        this->container.movement_component = new MovementComponent();
        this->container.game_component = new GameComponent();
    }

    this->container.movement_component->pos.x = x;
    this->container.movement_component->pos.y = y;
    this->container.graphic_component->createSprite(sprite, width, height, 1);
    this->container.graphic_component->setPosition(0, 0);
    this->container.event_component->setHitbox(x, y, width, height);
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
