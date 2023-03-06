/*
** EPITECH PROJECT, 2023
** R-Type.nosync
** File description:
** SystemManager
*/

#include "systems/SystemManager.hpp"
#include <string>
#include "iostream"

namespace rtype {

    SystemManager::SystemManager(QObject *parent) : QObject(parent), graphicSystem(nullptr), movementSystem(nullptr), networkSystem(nullptr)
    {
        _isConnected = false;
    }

    SystemManager::~SystemManager()
    {
    }

    void SystemManager::createGraphicSystem(SceneManager *manager)
    {
        graphicSystem = new GraphicSystem(this);
        if (networkSystem != nullptr)
            QObject::connect(networkSystem, SIGNAL(updateEntities(std::vector<EntityCreator_t*>)), graphicSystem, SLOT(onUpdateEntities(std::vector<EntityCreator_t *>)));
        QObject::connect(graphicSystem, SIGNAL(updateEntities(std::vector<EntityCreator_t *>)), manager, SLOT(onUpdateEntities(std::vector<EntityCreator_t *>)));
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
            QObject::connect(networkSystem, SIGNAL(updateEntities(std::vector<EntityCreator_t*>)), graphicSystem, SLOT(onUpdateEntities(std::vector<EntityCreator_t *>)));
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

    void SystemManager::updateNetwork()
    {
        if (!eventSystem->_connectInfos.empty() && _isConnected == false) {
            std::cout << "try to connect" << std::endl;

            // separate the ip and the port
            int size = eventSystem->_connectInfos.find(":");
            std::string ip = eventSystem->_connectInfos.substr(0, size);
            std::string port = eventSystem->_connectInfos.substr(size + 1, eventSystem->_connectInfos.length());
            networkSystem = new NetworkSystem(this, QString::fromStdString(ip), QString::fromStdString(port).toUInt());
            if (graphicSystem != nullptr)
               QObject::connect(networkSystem, SIGNAL(updateEntities(std::vector<EntityCreator_t *>)), graphicSystem, SLOT(onUpdateEntities(std::vector<EntityCreator_t *>)));
            if (movementSystem != nullptr)
               QObject::connect(movementSystem, SIGNAL(sendMovePlayer(DIRECTION)), networkSystem, SLOT(onSendMovePlayer(DIRECTION)));
            _isConnected = true;
        }
    }

    void SystemManager::gameQuit()
    {
        delete networkSystem;
    }
}