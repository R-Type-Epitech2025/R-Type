/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** EventSystem
*/

#include "./systems/EventSystem.hpp"
#include <iostream>

namespace rtype {
    namespace system {

        system::EventSystem::EventSystem()
        {
        }

        system::EventSystem::~EventSystem()
        {
        }

        void EventSystem::update(rtype::SceneManager *currentScene, sf::RenderWindow &window, sf::Event &event)
        {
            Scene *scene = currentScene->getCurrentScene();
            for (auto &NewEvent : _newEvent) {
                if (scene->getEntity(NewEvent->identity)->container.event_component->eventHandler(event, NewEvent->key, window)) {
                    std::cout << "scene Changed" << std::endl;
                    if (NewEvent->newScene) {
                        currentScene->setScene(NewEvent->newId);
                    }
                } 
            }
        }

        void EventSystem::CreateNewEvent(std::string identity, SceneManager *scene, std::string newId, bool newScene, EventSystemType type, sf::Keyboard::Key key) 
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
}