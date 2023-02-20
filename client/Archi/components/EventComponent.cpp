/*
** EPITECH PROJECT, 2023
** Archi
** File description:
** EventComponent
*/

#include "../Include/components/EventComponent.hpp"


namespace rtype{
    EventComponent::EventComponent()
    {
    }

    EventComponent::~EventComponent()
    {
    }

    void EventComponent::eventHandler(sf::Event event, sf::Keyboard::Key key, rtype::Action action, void(*direction)()){
            if (event.type == sf::Event::KeyPressed){   
                    if (event.key.code == key) {
                        if (action == rtype::Action::Click){
                            direction();
                        }
                    }    
            }   
    }
}