/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Core
*/

#include <ctime>

#include "Core.hpp"

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
        _systemManager->eventSystem->createNewEvent(4, gameMenu->_gameScene->getSceneName(), connectMenu->_connectMenu->getSceneName(), "connect");
        _systemManager->eventSystem->createNewEvent(4, connectMenu->_connectMenu->getSceneName(), mainMenu->_mainMenu->getSceneName(), "play");
    }
    
    int Core::run(int argc, char **argv)
    {
        sf::Event event;
        QCoreApplication game(argc, argv);
        std::srand(std::time(nullptr));
        QTimer *timer = new QTimer(&game);
        
        _systemManager->createGraphicSystem();
        _systemManager->createMovementSystem();
        //_systemManager->createNetworkSystem(QString(argv[1]), QString(argv[2]).toUInt());
        
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
            _systemManager->updateNetwork();
//            std::cout << "connect infos : " << _systemManager->eventSystem->_connectInfos << std::endl;
        });
        timer->start(30);
        return game.exec();
    }


    Core::~Core()
    {
    } 
}