/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** EventSystem
*/

#include "./systems/EventSystem.hpp"
#include <iostream>

namespace rtype {
    
    EventSystem::EventSystem()
    {
    }

    EventSystem::~EventSystem()
    {
    }

    void EventSystem::update(rtype::SceneManager *currentScene)
    {
        // check collision between entities
    }

    void EventSystem::createNewEvent(quint32 identity, SceneManager *scene, std::string newId, bool newScene, EventSystemType type, sf::Keyboard::Key key) 
    {
        NewEventComponent_t *newEvent = new NewEventComponent_t;

        newEvent->key = key;
        newEvent->identity = identity;
        newEvent->newId = newId;
        newEvent->newScene = newScene;
        newEvent->type = type;
        newEvent->scene = scene;

        _newEvent.push_back(newEvent);
    }
}