/*
** EPITECH PROJECT, 2023
** R-Type.nosync
** File description:
** SystemManager
*/

#include "systems/SystemManager.hpp"

namespace rtype {

    SystemManager::SystemManager(QObject *parent) : QObject(parent), graphicSystem(nullptr), movementSystem(nullptr), networkSystem(nullptr)
    {
    }

    SystemManager::~SystemManager()
    {
    }

    void SystemManager::createGraphicSystem()
    {
        graphicSystem = new GraphicSystem(this);
        if (networkSystem != nullptr)
            QObject::connect(networkSystem, SIGNAL(updateEntities(std::vector<Entity*>)), graphicSystem, SLOT(onUpdateEntities(std::vector<Entity *>)));
    }

    void SystemManager::createMovementSystem()
    {
        movementSystem = new MovementSystem(this);
        if (networkSystem != nullptr)
            QObject::connect(movementSystem, SIGNAL(sendMovePlayer(DIRECTION)), networkSystem, SLOT(onSendMovePlayer(DIRECTION)));
    }

    void SystemManager::createNetworkSystem(QString addr, quint32 port)
    {
        networkSystem = new NetworkSystem(this, addr, port);
        if (graphicSystem != nullptr)
            QObject::connect(networkSystem, SIGNAL(updateEntities(std::vector<Entity*>)), graphicSystem, SLOT(onUpdateEntities(std::vector<Entity *>)));
        if (movementSystem != nullptr)
            QObject::connect(movementSystem, SIGNAL(sendMovePlayer(DIRECTION)), networkSystem, SLOT(onSendMovePlayer(DIRECTION)));
    }

    void SystemManager::createEventSystem()
    {
        eventSystem = new EventSystem(this);
    }

    void SystemManager::updateEvents(SceneManager *currentScene, sf::Event &event)
    {
        eventSystem->update(currentScene, event);
    }

    void SystemManager::updateGraphic(SceneManager *Manager, uint64_t time)
    {
        graphicSystem->update(Manager, time);
    }

    void SystemManager::updateMovement(SceneManager *Manager, sf::Event &event)
    {
        movementSystem->update(Manager, event);
    }

    void SystemManager::gameQuit()
    {
        delete networkSystem;
    }
}
