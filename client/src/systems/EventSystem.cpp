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
        _connectInfos = "";
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
                if (tmp_entity->container.event_component != nullptr && tmp_entity->container.event_component->eventHandler(event, currentScene->window) == true) {
                    if (NewEvent->eventName == "connect")
                        _connectInfos = scene->getEntity(20)->container.graphic_component->getInputText();
                    currentScene->setScene(NewEvent->futureSceneName);
                    break;
                }
            }
        }
    } 

    void EventSystem::createNewEvent(quint32 entityId, std::string newSceneName, std::string sceneName, std::string eventName) 
    {
        NewEvent_t *newEvent = new NewEvent_t;
        newEvent->entityId = entityId;
        newEvent->futureSceneName = newSceneName;
        newEvent->currentSceneName = sceneName;
        newEvent->eventName = eventName;
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
}