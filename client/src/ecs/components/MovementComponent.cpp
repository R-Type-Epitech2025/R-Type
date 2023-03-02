/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** MovementComponent
*/
#include "ecs/components/MovementComponent.hpp"



//IL n'y a pas forcement d'implementation de celui la a faire 
namespace rtype{
    MovementComponent::MovementComponent(std::vector<int> positioninscreen, bool keyboardLink)
    {
        pos.x = positioninscreen[0];
        pos.y = positioninscreen[1];
        _link = keyboardLink;
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
}
