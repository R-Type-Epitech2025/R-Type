/*
** EPITECH PROJECT, 2023
** Archi
** File description:
** EventComponent
*/

#include "EventComponent.hpp"
#include <QtNetwork>

namespace rtype{
    EventComponent::EventComponent(EntityType entity, std::vector<int> positioninscreen, std::vector<int> sizeScreen)
    {
        this->entity = entity;
        this->_hitbox.x = positioninscreen[0];
        this->_hitbox.y = positioninscreen[1];
        this->_hitbox.width = sizeScreen[0];
        this->_hitbox.height = sizeScreen[1];
        this->is_hitbox = true;
    }

    EventComponent::~EventComponent()
    {
    }

    void EventComponent::setHitbox(int x, int y, int width, int height){
        this->_hitbox.x = x;
        this->_hitbox.y = y;
        this->_hitbox.width = width;
        this->_hitbox.height = height;
        this->is_hitbox = true;
    }
}