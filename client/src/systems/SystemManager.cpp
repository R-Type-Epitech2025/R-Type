/*
** EPITECH PROJECT, 2023
** R-Type.nosync
** File description:
** SystemManager
*/

#include "systems/SystemManager.hpp"

namespace rtype {

    SystemManager::SystemManager(QObject *parent) : QObject(parent), _graphicSystem(nullptr), _movementSystem(nullptr), _networkSystem(nullptr)
    {
    }

    SystemManager::~SystemManager()
    {
    }

    void SystemManager::createGraphicSystem()
    {
        _graphicSystem = new GraphicSystem(this);
        if (_networkSystem != nullptr)
            QObject::connect(_networkSystem, SIGNAL(updateEntities(std::vector<Entity *>)), _graphicSystem, SLOT(onUpdateEntities(std::vector<Entity *>)));
    }

    void SystemManager::createMovementSystem()
    {
        _movementSystem = new MovementSystem(this);
        if (_networkSystem != nullptr)
            QObject::connect(_movementSystem, SIGNAL(sendMovePlayer(DIRECTION)), _networkSystem, SLOT(onSendMovePlayer(DIRECTION)));
    }

    void SystemManager::createNetworkSystem(QString addr, quint32 port)
    {
        _networkSystem = new NetworkSystem(this, addr, port);
        if (_graphicSystem != nullptr)
            QObject::connect(_networkSystem, SIGNAL(updateEntities(std::vector<Entity *>)), _graphicSystem, SLOT(onUpdateEntities(std::vector<Entity *>)));
        if (_movementSystem != nullptr)
            QObject::connect(_movementSystem, SIGNAL(sendMovePlayer(DIRECTION)), _networkSystem, SLOT(onSendMovePlayer(DIRECTION)));
    }

    void SystemManager::gameQuit()
    {
        delete _networkSystem;
    }
}
