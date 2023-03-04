/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** EventSystem
*/

#include "./systems/EventSystem.hpp"
#include <iostream>

namespace rtype {
    
    EventSystem::EventSystem(QObject *parent) : QObject(parent)
    {
    }

    EventSystem::~EventSystem()
    {
    }

    void EventSystem::update(rtype::SceneManager *currentScene, sf::Event &event)
    {
        Scene *scene = currentScene->getCurrentScene();
        for (auto &NewEvent : _newEvent) {
            rtype::Entity *tmp_entity = scene->getEntity(NewEvent->identity);
            if (tmp_entity->container.event_component != NULL && tmp_entity->container.event_component->eventHandler(event, NewEvent->key, currentScene->window)) {
                if (NewEvent->newScene) {
                    currentScene->setScene(NewEvent->newId);
                }
            } 
        }
    }

    void EventSystem::createNewEvent(std::string identity, SceneManager *scene, std::string newId, bool newScene, EventSystemType type, sf::Keyboard::Key key) 
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
    
    // void EventSystem::update(std::vector<std::shared_ptr<Entity> > &entities)
    // {
    //     sf::Event event;
    //     while (_window.pollEvent(event))
    //     {
    //         if (event.type == sf::Event::Closed)
    //             _window.close();
    //         else if (event.type == sf::Event::MouseButtonPressed)
    //         { 
        
    //             entities.push_back(std::shared_ptr<Entity>(new Entity()));
    //             auto& newEntity = entities.back();
    //             newEntity->x = event.mouseButton.x;
    //             newEntity->y = event.mouseButton.y;
    //             if (entities.size() == 1){
    //                 newEntity->Player = true;
    //                 newEntity->color = "Red";
    //             }else{
    //                 newEntity->Player = false;
    //                 newEntity->color = "blue";
    //             }
    //             std::cout<<"New entity"<<std::endl;
    //         }
    //         for (int i = 0; i < entities.size(); i++){
    //             if (entities.at(i)->Player){   
    //                 _movement.LinkKeybordPosition(event, entities.at(i));
    //             }
    //         }
    //     }
    // }
}