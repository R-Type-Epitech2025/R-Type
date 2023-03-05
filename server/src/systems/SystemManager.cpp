/*
** EPITECH PROJECT, 2023
** R-Type.nosync
** File description:
** SystemManager
*/

#include "systems/SystemManager.hpp"

namespace rtype {

    SystemManager::SystemManager(QObject *parent) : QObject(parent), gameSystem(nullptr), movementSystem(nullptr), networkSystem(nullptr)
    {
    }

    SystemManager::~SystemManager()
    {
    }

    void SystemManager::createGameSystem()
    {
        gameSystem = new GameSystem(this);
        if (networkSystem != nullptr) {
            QObject::connect(networkSystem, SIGNAL(playerShootEvent(quint32)), gameSystem, SLOT(onPlayerShoot(quint32)));
            QObject::connect(networkSystem, SIGNAL(playerQuitEvent(quint32)), gameSystem, SLOT(onPlayerDisconnected(quint32)));
            QObject::connect(networkSystem, SIGNAL(playerConnectEvent(quint32)), gameSystem, SLOT(onNewPlayerConnected(quint32)));
        }
    }

    void SystemManager::createMovementSystem()
    {
        movementSystem = new MovementSystem(this);
        if (networkSystem != nullptr)
            QObject::connect(networkSystem, SIGNAL(playerMoveEvent(quint32, DIRECTION)), movementSystem, SLOT(onSendMovePlayer(quint32, DIRECTION)));
    }

    void SystemManager::createNetworkSystem()
    {
        networkSystem = new NetworkSystem(this);
        if (movementSystem != nullptr) {
            QObject::connect(networkSystem, SIGNAL(playerMoveEvent(quint32, DIRECTION)), movementSystem, SLOT(onSendMovePlayer(quint32, DIRECTION)));
        }
        if (gameSystem != nullptr) {
            QObject::connect(networkSystem, SIGNAL(playerShootEvent(quint32)), gameSystem, SLOT(onPlayerShoot(quint32)));
            QObject::connect(networkSystem, SIGNAL(playerQuitEvent(quint32)), gameSystem, SLOT(onPlayerDisconnected(quint32)));
            QObject::connect(networkSystem, SIGNAL(playerConnectEvent(quint32)), gameSystem, SLOT(onNewPlayerConnected(quint32)));
        }
    }

    // void SystemManager::updateEvents(SceneManager *currentScene, sf::Event &event)
    // {
    //     eventSystem->update(currentScene, event);
    // }

    void SystemManager::updateGraphic(SceneManager *Manager, uint64_t time)
     {
         graphicSystem->update(Manager, time);
     }

    // void SystemManager::updateMovement(SceneManager *Manager, sf::Event &event)
    // {
    //     movementSystem->update(Manager, event);
    // }

    // void SystemManager::gameQuit()
    // {
    //     delete networkSystem;
    // }
}
