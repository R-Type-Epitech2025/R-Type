/*
** EPITECH PROJECT, 2023
** Archi
** File description:
** EventComponent
*/

#include "ecs/components/EventComponent.hpp"
// #include <functional>

namespace rtype{
    EventComponent::EventComponent(rtype::EntityType entity)
    {
        this->entity = entity;
    }

    EventComponent::~EventComponent()
    {
    }

    bool EventComponent::eventHandler(sf::Event event, sf::Keyboard::Key key, sf::RenderWindow &window){
        sf::Vector2i position = sf::Mouse::getPosition(window);
        if (event.type == sf::Event::KeyPressed){   
            if (event.key.code == key) {
                if (sf::Mouse::getPosition(window).x >= _hitbox.x &&  sf::Mouse::getPosition(window).x <= _hitbox.x + _hitbox.width
                && sf::Mouse::getPosition(window).y >= _hitbox.y && sf::Mouse::getPosition(window).y <= _hitbox.y + _hitbox.height)
                    return true;
            }
        }
        return false;
    }

    void EventComponent::setHitbox(int x, int y, int width, int height){
        this->_hitbox.x = x;
        this->_hitbox.y = y;
        this->_hitbox.width = width;
        this->_hitbox.height = height;
        this->is_hitbox = true;
    }

    EntityType convertUint32ToEntityType(uint32_t type)
    {
        switch (type) {
            case 0:
                return EntityType::BACKGROUND;
            case 1:
                return EntityType::MAIN_PLAYER;
            case 2:
                return EntityType::PLAYER;
            case 3:
                return EntityType::BUTTON;
            case 4:
                return EntityType::BULLET;
            case 5:
                return EntityType::MOB;
            default:
                return EntityType::BACKGROUND;
        }
    }
}