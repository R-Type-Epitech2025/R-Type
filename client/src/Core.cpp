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
    Entity *InitPlayButton() {
        Entity *playButton = new Entity(rtype::EntityType::BUTTON, {300, 600}, {0, 0}, {300, 300}, 1.0, "./assets/button_play.png", 3);
        return playButton;
    }

    Entity *InitExitButton() {
        Entity *exitButton = new Entity(rtype::EntityType::BUTTON, {100, 900}, {0, 0}, {100, 100}, 1.0, "./assets/button_close.png", 3);
        return exitButton;
    }

    Entity *InitOptionButton() {
        Entity *optionButton = new Entity(rtype::EntityType::BUTTON, {600, 600}, {0, 0}, {300, 300}, 1.0, "./assets/button_settings.png", 2);
        return optionButton;
    }

    Entity *InitBackground() {
        Entity *background = new Entity(rtype::EntityType::BACKGROUND, {0, 0}, {0, 0}, {1920, 1080}, 1.0, "./assets/background.png", 1);
        return background;
    }

    Scene *ceateMenuScene() {
        Scene *mainMenu = new Scene("first");
        mainMenu->addEntity(InitBackground());
        mainMenu->addEntity(InitPlayButton());
        mainMenu->addEntity(InitExitButton());
        mainMenu->addEntity(InitOptionButton());
        
        return mainMenu;
    }



    Core::Core() : _sceneManager(new SceneManager()), _systemManager(new SystemManager())
    {
    }

    Scene *creategameScene()
    {
        int mobType = std::rand()%8 * 32;

        Entity *background = new Entity(EntityType::BACKGROUND ,{0, 0},{0 , 0}, {1920, 1080}, 1.0, "./assets/backgournd2.jpg", 10);
        Entity *button = new Entity(EntityType::BUTTON , {500, 500},{0, 0}, {500, 500}, 1.0, "./assets/button_play.png", 11);
        Entity *spaceShip = new Entity(EntityType::MAIN_PLAYER , {500, 500},{0, 0}, {500, 500}, 1.0, "./assets/r-typesheet42.gif", 12);
        Entity *ennemy = new Entity(EntityType::MOB, {1000, std::rand()%1064}, {mobType, 0}, {32, 32}, 3.0, "./assets/sprites.png", 13);

        Scene *scene = new Scene("second");
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
        
        _systemManager->eventSystem->createNewEvent(2, "second", "first");
        Scene *menu = ceateMenuScene();
        Scene *gameScene = creategameScene();
        _sceneManager->addScene(gameScene);
        _sceneManager->addScene(menu);
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
        return game.exec();
    }


    Core::~Core()
    {
    } 
}