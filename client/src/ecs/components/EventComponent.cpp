/*
** EPITECH PROJECT, 2023
** Archi
** File description:
** EventComponent
*/

#include "ecs/components/EventComponent.hpp"


namespace rtype{
    EventComponent::EventComponent(rtype::EntityType entity)
    {
        this->entity = entity;
    }

    EventComponent::~EventComponent()
    {
    }

   void EventComponent::eventHandler(sf::Event event, sf::Keyboard::Key key, sf::RenderWindow &window, void(*direction)()){
        sf::Vector2i position = sf::Mouse::getPosition(window);
            if (event.type == sf::Event::KeyPressed){   
                    if (event.key.code == key) {
                            if (sf::Mouse::getPosition(window).x >= _hitbox.x &&  sf::Mouse::getPosition(window).x <= _hitbox.x + _hitbox.width
                            && sf::Mouse::getPosition(window).y >= _hitbox.y && sf::Mouse::getPosition(window).y <= _hitbox.y + _hitbox.height)
                                direction();
                        }
                    }    
   }

     void EventComponent::eventHandler(sf::Event event, sf::Mouse::Button key, sf::RenderWindow &window, void(*direction)()){
        sf::Vector2i position = sf::Mouse::getPosition(window);
      
        if (sf::Mouse::isButtonPressed(key)) {
            if (this->entity == rtype::EntityType::BUTTON){
                if (sf::Mouse::getPosition(window).x >= _hitbox.x &&  sf::Mouse::getPosition(window).x <= _hitbox.x + _hitbox.width
                && sf::Mouse::getPosition(window).y >= _hitbox.y && sf::Mouse::getPosition(window).y <= _hitbox.y + _hitbox.height)
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