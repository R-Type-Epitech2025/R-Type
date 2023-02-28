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
}