/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Core
*/

#include <ctime>

#include "Core.hpp"
#include "iostream"

namespace rtype {
    Core::Core() : _sceneManager(new SceneManager()), _systemManager(new SystemManager())
    {
    }

    int Core::run(int argc, char **argv)
    {
        QCoreApplication game(argc, argv);
        _systemManager->createGameSystem();
        _systemManager->createNetworkSystem();
        _systemManager->createMovementSystem();
        QTimer *timer = new QTimer(&game);

        QObject::connect(timer, &QTimer::timeout, [&]() {
            _systemManager->UpdateG(_sceneManager, timer->interval());
            // movementSystem->update(_sceneManager, event);
            // eventSystem->update(_sceneManager);$
        });
        timer->start(30);
        return game.exec();
    }


    Core::~Core()
    {
    } 
}