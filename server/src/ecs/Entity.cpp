/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Entity
*/

#include "ecs/Entity.hpp"


namespace rtype {
    Entity::Entity(EntityType type, std::vector<int> positioninscreen, std::vector<int> positioninsprite_sheet , std::vector<int> sizespritesheet, float scale, std::string sprite, quint32 id)
    {
        this->container.event_component = NULL;
        this->container.game_component = NULL;
        this->container.graphic_component = new GraphicComponent(sprite, positioninsprite_sheet, sizespritesheet, scale, positioninscreen);
        this->container.movement_component = NULL;
        std::vector<int> velociity = {0, 0};
        std::vector<int> bulletVelociity = {3, 0};
        std::vector<int> hitboxSize = {(int) (sizespritesheet[0] * scale), (int) (sizespritesheet[1] * scale)};

        switch (type) {
            case MOB:
                this->container.event_component = new EventComponent(type, positioninscreen, hitboxSize);
                this->container.movement_component = new MovementComponent(positioninscreen, false, velociity);
                this->container.game_component = new GameComponent();
                break;
            case MAIN_PLAYER:
                this->container.event_component = new EventComponent(type, positioninscreen, hitboxSize);
                this->container.movement_component = new MovementComponent(positioninscreen, true, velociity);
                this->container.game_component = new GameComponent();
                break;
            case PLAYER:
                this->container.event_component = new EventComponent(type, positioninscreen, hitboxSize);
                this->container.movement_component = new MovementComponent(positioninscreen, false, velociity);
                this->container.game_component = new GameComponent();
                break;
            case BULLET:
                this->container.event_component = new EventComponent(type, positioninscreen, hitboxSize);
                this->container.movement_component = new MovementComponent(positioninscreen, false, bulletVelociity);
                this->container.game_component = new GameComponent();
                break;
            case BUTTON:
                this->container.event_component = new EventComponent(type, positioninscreen, hitboxSize);
                this->container.game_component = new GameComponent();
                break;
            case BACKGROUND:
                this->container.movement_component = new MovementComponent(positioninscreen, false, velociity);
                this->container.game_component = new GameComponent();
                break;
        }
        this->_type = type;

        if (id == 0)
            this->_id = std::hash<std::string>{}(sprite);
        else
            this->_id = id;
    }

    Entity::~Entity()
    {
    }

    DIRECTION Entity::get_directions(){
        return direction;
    }

    void Entity::set_direction(DIRECTION direction )  {
        this->direction = direction;
    }

    quint32 Entity::getId() const {
        return _id;
    }

    quint32 Entity::getEntityType() const {
        switch (_type)
        {
        case MAIN_PLAYER:
            return 1;
        case PLAYER:
            return 2;
        case MOB:
            return 5;
        case BULLET:
            return 4;
        case BUTTON:
            return 3;
        case BACKGROUND:
            return 0;
        default:
            throw std::runtime_error("Unknown entity type");
            return 1000;
        }
    }

    quint32 Entity::getSpritesheetIndex() const {
        return container.graphic_component->getSpritesheetIndex();
    }

    std::vector<quint32> Entity::getSheetPosition() const {
        return container.graphic_component->getSheetPosition();
    }

    std::vector<quint32> Entity::getSheetSize() const {
        return container.graphic_component->getSheetSize();
    }

    quint32 Entity::getScale() const {
        return container.graphic_component->getScale();
    }

    std::vector<quint32> Entity::getPosition() const {
        return container.graphic_component->getPosition();
    }
}

