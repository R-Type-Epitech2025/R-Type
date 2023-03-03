/*
** EPITECH PROJECT, 2023
** client
** File description:
** GameSystem
*/

#include "GameSystem.hpp"

namespace rtype{
    GameSystem::GameSystem(QObject *parent) : QObject(parent)
    {
    }

    GameSystem::~GameSystem()
    {
    }

    void GameSystem::onNewPlayerConnected(quint16 id)
    {
        std::cout << "New player connected with id: " << id << std::endl;
    }
}
