/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** MovementComponent
*/
#include "ecs/components/MovementComponent.hpp"

namespace rtype{
    MovementComponent::MovementComponent(std::vector<int> positioninscreen, bool keyboardLink, std::vector<int> setVelocity)
    {
        pos.x = positioninscreen[0];
        pos.y = positioninscreen[1];
        velocity.x = setVelocity[0];
        velocity.y = setVelocity[1];
        _link = keyboardLink;
        isParallax = false;
    }

    MovementComponent::~MovementComponent()
    {
    }

    void MovementComponent::LinktoKeybord(bool link){
        _link = link;
    }

    bool MovementComponent::is_linked() const{
        return _link;
    }

    void MovementComponent::applyVelocity()
    {
        pos.x += velocity.x;
        pos.y += velocity.y;  
    }

    void MovementComponent::checkParallax()
    {
        if (isParallax == false)
            return;
        if (pos.x <= -1920)
            pos.x = 1920;
    }
}
