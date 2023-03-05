/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Entity
*/

#include "Entity.hpp"

namespace rtype {
    Entity::Entity(EntityType type, std::vector<int> positioninscreen, std::vector<int> positioninsprite_sheet , std::vector<int> sizespritesheet, float scale, std::string sprite, uint32_t id, bool isPrint, std::vector<int> velocity)
    {
        this->container.event_component = nullptr;
        this->container.graphic_component = new GraphicComponent(sprite, positioninsprite_sheet, sizespritesheet, scale, positioninscreen, isPrint);
        this->container.movement_component = nullptr;
        
        std::vector<int> hitboxSize = {(int) (sizespritesheet[0] * scale), (int) (sizespritesheet[1] * scale)};
    
        switch (type) {
            case MOB:
                this->container.event_component = new EventComponent(type, positioninscreen, hitboxSize);
                this->container.movement_component = new MovementComponent(positioninscreen, false, velocity);
                break;
            case MAIN_PLAYER:
                this->container.event_component = new EventComponent(type, positioninscreen, hitboxSize);
                this->container.movement_component = new MovementComponent(positioninscreen, true, velocity);
                break;
            case PLAYER:
                this->container.event_component = new EventComponent(type, positioninscreen, hitboxSize);
                this->container.movement_component = new MovementComponent(positioninscreen, false, velocity);
                break;
            case BULLET:
                this->container.event_component = new EventComponent(type, positioninscreen, hitboxSize);
                this->container.movement_component = new MovementComponent(positioninscreen, false, velocity);
                break;
            case BUTTON:
                this->container.event_component = new EventComponent(type, positioninscreen, hitboxSize);
                break;
            case BACKGROUND:
                this->container.movement_component = new MovementComponent(positioninscreen, false, velocity);
                break;
            case TEXT:
            this->container.event_component = new EventComponent(type, positioninscreen, hitboxSize);
            break;
            }
        this->_type = type;
        if (id == 0)
            this->_id = std::hash<std::string>{}(sprite);
        else
            this->_id = id;
    }

    Entity::Entity(EntityType type, std::vector<int> positionInScreen, u_int32_t fontSize, sf::Color& textColor, uint32_t id, bool isPrint)
    {
        this->container.event_component = nullptr;
        this->container.graphic_component = new GraphicComponent(positionInScreen, fontSize, textColor, isPrint);
        this->container.movement_component = nullptr;
        this->_type = type;
        if (id == 0)
            this->_id = std::hash<std::string>{}(std::to_string(fontSize));
        else
            this->_id = id;
    }


    DIRECTION Entity::get_directions(){
        return direction;
    }

    void Entity::set_direction(DIRECTION direction )  {
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