/*
** EPITECH PROJECT, 2023
** Archi
** File description:
** EventComponent
*/

#include "ecs/components/EventComponent.hpp"


namespace rtype{
    EventComponent::EventComponent()
    {
    }

    EventComponent::~EventComponent()
    {
    }

    void EventComponent::eventHandler(sf::Event event, sf::Keyboard::Key key, void(*direction)()){
            if (event.type == sf::Event::KeyPressed){   
                if (event.key.code == key) {
                        direction();
                }    
            }   
    }

    void EventComponent::setHitbox(int x, int y, int width, int height){
        this->_hitbox.x = x;
        this->_hitbox.y = y;
        this->_hitbox.width = width;
        this->_hitbox.height = height;
        this->is_hitbox = true;
    }
}