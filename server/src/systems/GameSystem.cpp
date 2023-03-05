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

    void GameSystem::onNewPlayerConnected(quint32 id)
    {
        std::cout << "New player connected with id: " << id << std::endl;
    }

    void GameSystem::onPlayerDisconnected(quint32 id)
    {
        std::cout << "Player disconnected with id: " << id << std::endl;
    }

    void GameSystem::onPlayerShoot(quint32 id)
    {
        std::cout << "Player " << id << " shoot" << std::endl;
    }
}