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
    //à mettre dans le update du game system
    Entity *spawnEnnemy()
    {
        std::cout << "test1" << std::endl;
        int mobType = std::rand()%8 * 32;
        Entity *entity = new Entity(EntityType::MOB, {1000, std::rand()%1064}, {mobType, 0}, {32, 32}, 3.0, "./assets/sprites.png", "ennemy1");
        // entity->container.graphic_component->setSpritePosition(1000, 100);
        // entity->container.movement_component->velocity = 10;
        // entity->container.graphic_component->setPosition(entity->container.graphic_component->position.x -= entity->container.movement_component->velocity, entity->container.graphic_component->position.y);
        std::cout << "test2" << std::endl;
        return entity;
    }

    Core::Core() : _sceneManager(new SceneManager()), _systemManager(new SystemManager())
    {
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
        Entity *entity = new Entity(EntityType::BACKGROUND ,{0, 0},{0 , 0}, {1920, 1080}, 1.0, "./assets/backgournd2.jpg", "background");
        Entity *entity1 = new Entity(EntityType::BUTTON , {500, 500},{0, 0}, {500, 500}, 1.0, "./assets/button_play.png", "play");
        Entity *spaceShip = new Entity(EntityType::MAIN_PLAYER , {500, 500},{0, 0}, {500, 500}, 1.0, "./assets/r-typesheet42.gif", "spaceship");
        Entity *ennemy = spawnEnnemy();
        
        Scene *scene = new Scene();
        scene->addEntity(entity);
        scene->addEntity(entity1);
        scene->addEntity(spaceShip);
        scene->addEntity(ennemy);
        _systemManager->eventSystem->createNewEvent("play", _sceneManager, "second", true, EventSystemType::CHANGESCENE, sf::Keyboard::Key::Escape);
        //Scene *scene2 = new Scene();
        //scene2->addEntity(entity);
        //scene2->addEntity(entity);

        _sceneManager->addScene("first" ,scene);
        //sceneManager->addScene("second" ,scene2);
        _sceneManager->setScene("first");
        //sceneManager, graphicSystem, movementSystem, &event, eventSystem
        QObject::connect(timer, &QTimer::timeout, [&]() {
            //std::vector<Entity*> entities = sceneManager->getCurrentScene()->get_entities();
            //Entity *player = NULL;
            //for (Entity *test_entity : entities){
            //    if (test_entity->_type == EntityType::MAIN_PLAYER)
            //        player = test_entity;
            //}

            while (_sceneManager->window.pollEvent(event)){
                if (event.type == sf::Event::Closed) 
                    exit(0);
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                    exit(0);
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                    Entity *test = new Entity(EntityType::BULLET , {spaceShip->container.movement_component->pos.y, spaceShip->container.movement_component->pos.y},{0, 0}, {500, 500}, 1.0, "./assets/r-typesheet42.gif", "bullet");
    //                Entity *test = new Entity(EntityType::BULLET , {spaceShipe->container.movement_component->pos.y, spaceShipe->container.movement_component->pos.y},{0, 0}, {500, 500}, {500, 500}, "./assets/test_image.jpg");
                    _sceneManager->getCurrentScene()->addEntity(test);
                    
                }
                
            }
            
            //sceneManager->getCurrentScene();
            _systemManager->updateGraphic(_sceneManager, 12);
            _systemManager->updateMovement(_sceneManager, event);
            _systemManager->updateEvents(_sceneManager, event);

            // entity1->container.event_component->eventHandler(event, sf::Mouse::Button::Left, window, print);
        });
        timer->start(30);
        std::cout <<"test the end"<< std::endl;
        return game.exec();
    }


    Core::~Core()
    {
    } 
}