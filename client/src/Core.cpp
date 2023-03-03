/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Core
*/

#include <ctime>

#include "Core.hpp"
#include "iostream"

void print()
{
    std::cout << "test" << std::endl;
}

namespace rtype {
    Core::Core() : _sceneManager(new SceneManager()), _systemManager(new SystemManager())
    {
    }

    Scene *creategameScene()
    {
        int mobType = std::rand()%8 * 32;

        Entity *background = new Entity(EntityType::BACKGROUND ,{0, 0},{0 , 0}, {1920, 1080}, 2.0, "./assets/backgournd2.jpg", "background");
        Entity *button = new Entity(EntityType::BUTTON , {500, 500},{0, 0}, {500, 500}, 1.0, "./assets/button_play.png", "play");
        Entity *spaceShip = new Entity(EntityType::MAIN_PLAYER , {500, 500},{0, 0}, {500, 500}, 1.0, "./assets/r-typesheet42.gif", "spaceship");
        Entity *ennemy = new Entity(EntityType::MOB, {1000, std::rand()%1064}, {mobType, 0}, {32, 32}, 3.0, "./assets/sprites.png", "ennemy1");

        Scene *scene = new Scene();
        scene->addEntity(background);
        scene->addEntity(button);
        scene->addEntity(spaceShip);
        scene->addEntity(ennemy);

        return scene;
    }
    
    //, SceneManager *sceneManager
    int Core::run(int argc, char **argv)
    {
        sf::Event event;
        QCoreApplication game(argc, argv);
        std::srand(std::time(nullptr));
        QTimer *timer = new QTimer(&game);
        
        _systemManager->createGraphicSystem();
        _systemManager->createMovementSystem();
        _systemManager->createEventSystem();
        
        Scene *gameScene = creategameScene();

        _sceneManager->addScene("first" ,gameScene);
        _sceneManager->setScene("first");
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
        std::cout <<"test the end"<< std::endl;
        return game.exec();
    }


    Core::~Core()
    {
    } 
}