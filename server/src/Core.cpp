/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Core
*/

#include <ctime>
#include <QElapsedTimer>

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
        Scene *scene = new Scene();
        _sceneManager->addScene("game1", scene);
        _sceneManager->setScene("game1");

        QObject::connect(timer, &QTimer::timeout, [&]() {
            _systemManager->updateGame(_sceneManager);
            _systemManager->updateGraphic(_sceneManager);
            // graphicSystem->update(_sceneManager, 12);
            // movementSystem->update(_sceneManager, event);
            // eventSystem->update(_sceneManager);
        });
        timer->start(30);
        return game.exec();
    }


    Core::~Core()
    {
    } 
}