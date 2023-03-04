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
    
        for (auto &NewEvent : _eventsList) {
            if (NewEvent->currentSceneName != scene->getSceneName())
                continue;
            else {
                Entity *tmp_entity = scene->getEntity(NewEvent->entityId);
                if (tmp_entity->container.event_component != NULL && tmp_entity->container.event_component->eventHandler(event, currentScene->window) == true) {
                    currentScene->setScene(NewEvent->futureSceneName);
                    break;
                }
            }
        }
        scene = currentScene->getCurrentScene();
    } 

    void EventSystem::createNewEvent(u_int32_t entityId, std::string newSceneName, std::string sceneName) 
    {
        NewEvent_t *newEvent = new NewEvent_t;
        newEvent->entityId = entityId;
        newEvent->futureSceneName = newSceneName;
        newEvent->currentSceneName = sceneName;
        _eventsList.push_back(newEvent);
    }

    bool EventSystem::getCollision(Entity *entity, Entity *collideEntity) const
    {
        hitbox_t hitbox = entity->container.event_component->getHitbox();
        hitbox_t collideHitbox = collideEntity->container.event_component->getHitbox();

        if (hitbox.x < collideHitbox.x + collideHitbox.width &&
            hitbox.x + hitbox.width > collideHitbox.x &&
            hitbox.y < collideHitbox.y + collideHitbox.height &&
            hitbox.y + hitbox.height > collideHitbox.y) {
            return true;
        }
        return false;
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
    //         }
    //         for (int i = 0; i < entities.size(); i++){
    //             if (entities.at(i)->Player){   
    //                 _movement.LinkKeybordPosition(event, entities.at(i));
    //             }
    //         }
    //     }
    // }
}