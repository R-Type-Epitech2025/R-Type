/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Entity
*/

#include "ecs/Entity.hpp"


rtype::Entity::Entity(rtype::EntityType type, std::vector<int> positioninscreen, std::vector<int> positioninsprite_sheet , std::vector<int> sizespritesheet, float scale, std::string sprite, std::string id)
{
    this->container.event_component = NULL;
    this->container.game_component = NULL;
    this->container.graphic_component = NULL;
    this->container.movement_component = NULL;

    if (type == rtype::EntityType::MAIN_PLAYER){
        this->container.event_component = new EventComponent(type);
        this->container.graphic_component = new GraphicComponent();
        this->container.movement_component = new MovementComponent();
        this->container.game_component = new GameComponent();
        this->container.movement_component->LinktoKeybord(true);
    } else {
        this->container.event_component = new EventComponent(type);
        this->container.graphic_component = new GraphicComponent();
        this->container.movement_component = new MovementComponent();
        this->container.game_component = new GameComponent();
    }

    this->container.movement_component->pos.x = positioninscreen.at(0);
    this->container.movement_component->pos.y = positioninscreen.at(1);
    this->container.graphic_component->createSprite(sprite, sizespritesheet[0], sizespritesheet[1], 1);
    this->container.graphic_component->setSize(100,100);
    this->container.graphic_component->setPosition(positioninscreen.at(0),  positioninscreen.at(1));
    this->container.event_component->setHitbox(positioninscreen.at(0), positioninscreen.at(1), 100, 100);
    // this->direction = rtype::DIRECTION::FORWARD;
    this->_type = type;
    this->_id = id;
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
            this->container.event_component = new EventComponent(this->_type);
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
