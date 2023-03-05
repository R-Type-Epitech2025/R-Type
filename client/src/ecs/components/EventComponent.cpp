/*
** EPITECH PROJECT, 2023
** Archi
** File description:
** EventComponent
*/

#include "ecs/components/EventComponent.hpp"
// #include <functional>

namespace rtype{
    EventComponent::EventComponent(rtype::EntityType entity, std::vector<int> positioninscreen, std::vector<int> sizeScreen)
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

    bool EventComponent::eventHandler(sf::Event event, sf::RenderWindow &window){

        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            if (mousePos.x >= this->_hitbox.x && mousePos.x <= this->_hitbox.x + this->_hitbox.width &&
                mousePos.y >= this->_hitbox.y && mousePos.y <= this->_hitbox.y + this->_hitbox.height) {
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

    hitbox EventComponent::getHitbox() const {
        return this->_hitbox;
    }

    EntityType convertUint32ToEntityType(quint32 type)
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
            case 6:
                return EntityType::TEXT;
            default:
                return EntityType::BACKGROUND;
        }
    }
}