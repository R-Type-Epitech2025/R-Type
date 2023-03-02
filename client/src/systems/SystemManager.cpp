/*
** EPITECH PROJECT, 2023
** R-Type.nosync
** File description:
** SystemManager
*/

#include "systems/SystemManager.hpp"

namespace rtype {
    SystemManager::SystemManager()
    : _graphicSystem(nullptr), _movementSystem(nullptr), _networkSystem(nullptr)
    {
    }

    SystemManager::~SystemManager()
    {
    }

    void SystemManager::setGraphicSystem(GraphicSystem *graphicSystem)
    {
        _graphicSystem = graphicSystem;
        if (_networkSystem != nullptr)
            QObject::connect(_networkSystem, SIGNAL(updateSprites(std::list<Entity *>)), _graphicSystem, SLOT(onUpdateSprites(std::vector<Entity *>)));
    }

    void SystemManager::setMovementSystem(MovementSystem *movementSystem)
    {
        _movementSystem = movementSystem;
        if (_networkSystem != nullptr)
            QObject::connect(_movementSystem, SIGNAL(sendMovePlayer(DIRECTION)), _networkSystem, SLOT(onSendMovePlayer(DIRECTION)));
    }

    void SystemManager::setNetworkSystem(NetworkSystem *networkSystem)
    {
        _networkSystem = networkSystem;
        if (_graphicSystem != nullptr)
            QObject::connect(_networkSystem, SIGNAL(updateSprites(std::list<Entity *>)), _graphicSystem, SLOT(onUpdateSprites(std::list<Entity *>)));
        if (_movementSystem != nullptr)
            QObject::connect(_movementSystem, SIGNAL(sendMovePlayer(DIRECTION)), _networkSystem, SLOT(onSendMovePlayer(DIRECTION)));
    }
}
