/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Entity
*/

#include "../Include/Entity.hpp"


rtype::Entity::Entity()
{
    this->container.event_component = NULL;
    this->container.game_component = NULL;
    this->container.graphic_component = NULL;
    this->container.movement_component = NULL;
}


void rtype::Entity::add_Container(const ComponentType &componentype){
    switch (componentype){
        case ComponentType::GameComponent: 
            this->container.game_component = new GameComponent();
            break;
        case ComponentType::GraphicComponent:
            this->container.graphic_component = new GraphicComponent();
            break;
        case ComponentType::MovemementComponent:
            this->container.movement_component = new MovementComponent();
            break;
    }
}



rtype::Entity::~Entity()
{
}
