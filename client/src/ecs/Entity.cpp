/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Entity
*/

#include "ecs/Entity.hpp"

namespace rtype {
    Entity::Entity(rtype::EntityType type, std::vector<int> positioninscreen, std::vector<int> positioninsprite_sheet , std::vector<int> sizespritesheet, float scale, std::string sprite, std::string id)
    {
        this->container.event_component = nullptr;
        this->container.graphic_component = new GraphicComponent(sprite, positioninsprite_sheet, sizespritesheet, scale, positioninscreen);
        this->container.movement_component = nullptr;
        
        std::vector<int> velociity = {0, 0};
        std::vector<int> bulletVelociity = {3, 0};
        std::vector<int> hitboxSize = {(int) (sizespritesheet[0] * scale), (int) (sizespritesheet[1] * scale)};
    
        switch (type) {
            case MOB:
                this->container.event_component = new EventComponent(type, positioninscreen, hitboxSize);
                this->container.movement_component = new MovementComponent(positioninscreen, false, velociity);
                break;
            case MAIN_PLAYER:
                this->container.event_component = new EventComponent(type, positioninscreen, hitboxSize);
                this->container.movement_component = new MovementComponent(positioninscreen, true, velociity);
                break;
            case PLAYER:
                this->container.event_component = new EventComponent(type, positioninscreen, hitboxSize);
                this->container.movement_component = new MovementComponent(positioninscreen, false, velociity);
                break;
            case BULLET:
                this->container.event_component = new EventComponent(type, positioninscreen, hitboxSize);
                this->container.movement_component = new MovementComponent(positioninscreen, false, bulletVelociity);
                break;
            case BUTTON:
                this->container.event_component = new EventComponent(type, positioninscreen, hitboxSize);
                break;
            case BACKGROUND:
                this->container.movement_component = new MovementComponent(positioninscreen, false, velociity);
                break;
            case TEXT:
            this->container.event_component = new EventComponent(type, positioninscreen, hitboxSize);
            this->container.game_component = new GameComponent();
    }
        this->_type = type;
        this->_id = id;
    }


    DIRECTION rtype::Entity::get_directions(){
        return direction;
    }

    void Entity::set_direction(rtype::DIRECTION direction )  {
        this->direction = direction;
    }
    
    Entity::~Entity()
    {
        if (this->container.event_component != nullptr)
            delete this->container.event_component;
        if (this->container.graphic_component != nullptr)
            delete this->container.graphic_component;
        if (this->container.movement_component != nullptr)
            delete this->container.movement_component;
    }
}