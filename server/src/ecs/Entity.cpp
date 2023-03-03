/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Entity
*/

#include "ecs/Entity.hpp"


rtype::Entity::Entity(rtype::EntityType type, std::vector<int> positioninscreen, std::vector<int> positioninsprite_sheet , std::vector<int> sizespritesheet, std::vector<int> sizeScreen, std::string sprite, std::string id)
{
    this->container.event_component = NULL;
    this->container.game_component = NULL;
    this->container.graphic_component = new GraphicComponent(sprite, positioninsprite_sheet, sizespritesheet, sizeScreen, positioninscreen);
    this->container.movement_component = NULL;
    std::vector<int> velociity = {0, 0};
    std::vector<int> bulletVelociity = {3, 0};
    
    switch (type) {
        case MOB:
            this->container.event_component = new EventComponent(type, positioninscreen, sizeScreen);
            this->container.movement_component = new MovementComponent(positioninscreen, false, velociity);
            this->container.game_component = new GameComponent();
            break;
        case MAIN_PLAYER:
            this->container.event_component = new EventComponent(type, positioninscreen, sizeScreen);
            this->container.movement_component = new MovementComponent(positioninscreen, true, velociity);
            this->container.game_component = new GameComponent();
            break;
        case PLAYER:
            this->container.event_component = new EventComponent(type, positioninscreen, sizeScreen);
            this->container.movement_component = new MovementComponent(positioninscreen, false, velociity);
            this->container.game_component = new GameComponent();
            break;
        case BULLET:
            this->container.event_component = new EventComponent(type, positioninscreen, sizeScreen);
            this->container.movement_component = new MovementComponent(positioninscreen, false, bulletVelociity);
            this->container.game_component = new GameComponent();
            break;
        case BUTTON:
            this->container.event_component = new EventComponent(type, positioninscreen, sizeScreen);
            this->container.game_component = new GameComponent();
            break;
        case BACKGROUND:
            this->container.movement_component = new MovementComponent(positioninscreen, false, velociity);
            this->container.game_component = new GameComponent();
            break;
    }
    this->_type = type;
    this->_id = id;
}


//void rtype::Entity::add_Container(const ComponentType &componentype){
//    switch (componentype){
//        case ComponentType::GAMECOMPONENT: 
//            this->container.game_component = new GameComponent();
//            break;
//        case ComponentType::GRAPHICCOMPONENT:
//            this->container.graphic_component = new GraphicComponent();
//            break;
//        case ComponentType::MOVEMENTCOMPONENT:
//            this->container.movement_component = new MovementComponent();
//            if (_type == rtype::EntityType::MAIN_PLAYER)
//                this->container.movement_component->LinktoKeybord(true);
//            break;
//        case ComponentType::EVENTCOMPONENT:
//            this->container.event_component = new EventComponent(this->_type);
//            break;
//    }
//}

    rtype::DIRECTION rtype::Entity::get_directions(){
        return direction;
    }

    void rtype::Entity::set_direction(rtype::DIRECTION direction )  {
        this->direction = direction;
    }
    rtype::Entity::~Entity()
    {
    }
