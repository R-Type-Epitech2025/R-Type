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

    // void MovementComponent::Parralax(Entity *entity, sf::Sprite &background1, sf::Sprite &background2)
    // {
    //     if (background1.getPosition().x < -background1.getTexture()->getSize().x) {
    //         background1.setPosition(background2.getPosition().x + background2.getTexture()->getSize().x, 0);
    //     }
    // }
}
