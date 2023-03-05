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
        ConnectMenu *connectMenu = new ConnectMenu();
        GameScene *gameMenu = new GameScene();
        MainMenu *mainMenu = new MainMenu();

        _sceneManager->addScene(connectMenu->_connectMenu);
        _sceneManager->addScene(gameMenu->_gameScene);
        _sceneManager->addScene(mainMenu->_mainMenu);
        _sceneManager->setScene(mainMenu->_mainMenu->getSceneName());      

        _systemManager->createEventSystem();

        _systemManager->eventSystem->createNewEvent(4, gameMenu->_gameScene->getSceneName(), mainMenu->_mainMenu->getSceneName());
    }
    
    int Core::run(int argc, char **argv)
    {
        sf::Event event;
        QCoreApplication game(argc, argv);
        std::srand(std::time(nullptr));
        QTimer *timer = new QTimer(&game);
        
        _systemManager->createGraphicSystem();
        _systemManager->createMovementSystem();
        //_systemManager->createEventSystem();
        _systemManager->createNetworkSystem(QString(argv[1]), QString(argv[2]).toUInt());
        
        //_systemManager->eventSystem->createNewEvent(2, "second", "first");
        //Scene *menu = ceateMenuScene();
        //Scene *gameScene = creategameScene();
        //_sceneManager->addScene(gameScene);
        //_sceneManager->addScene(menu);
        //_sceneManager->setScene("first");
        //sceneManager, graphicSystem, movementSystem, &event, eventSystem
        QObject::connect(timer, &QTimer::timeout, [&]() {
            
            while (_sceneManager->window.pollEvent(event)){
                if (event.type == sf::Event::Closed) 
                    exit(0);
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                    exit(0);
            }
            _systemManager->updateGraphic(_sceneManager, 12);
            _systemManager->updateMovement(_sceneManager, event);
            _systemManager->updateEvents(_sceneManager, event);
        });
        timer->start(30);
        return game.exec();
    }


    Core::~Core()
    {
    } 
}