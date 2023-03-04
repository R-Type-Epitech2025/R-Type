/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Core
*/

#include <ctime>

#include "Core.hpp"
#include "iostream"
#include <QElapsedTimer>

void print()
{
    std::cout << "test" << std::endl;
}

namespace rtype {
    //à mettre dans le update du game system
    Entity *BulletSpawner(Entity *mob, Entity *bullet)
    {
        Entity *tmp(new Entity(*bullet));
        tmp->container.movement_component->pos = {mob->container.graphic_component->position.x, mob->container.graphic_component->position.y + 50};
        tmp->container.movement_component->velocity.x = -20;
        return tmp;
    }

    void EnnemyShoot(Scene *scene)
    {
        Entity *bullet = new Entity(EntityType::BULLET, {1920, 0}, {16, 240}, {16, 16}, 2.0, "./assets/sprites.png", "bulletTEST");
        for (auto &entity : scene->get_entities()) {
            if (entity->_id == "ennemy1") {
                scene->addEntity(BulletSpawner(entity, bullet));
            }
            if (entity->_id == "ennemy2") {
                scene->addEntity(BulletSpawner(entity, bullet));
            }
        }
    }

    std::vector<Entity *> ennemy1()
    {
        std::cout << ennemy1 << std::endl;
        std::vector<Entity *> entities;
        for (int i = 0; i < 9; i++) {
            Entity *entity;
            if (i < 4) {
                entity = new Entity(EntityType::MOB, {2200 - i * 70, 50 + i * 100}, {0, 0}, {36, 36}, 3.0, "./assets/ennemy1.gif", "ennemy1");
            } else {
                entity = new Entity(EntityType::MOB, {1920 + (i - 4) * 70, 50 + i * 100}, {0, 0}, {36, 36}, 3.0, "./assets/ennemy1.gif", "ennemy1");
            };
            entity->container.movement_component->velocity.x = -10;
            entities.push_back(entity);
        }
        return entities;
    }

    std::vector<Entity *> ennemy2()
    {
        std::vector<Entity *> entities;
        Entity *entity = new Entity(EntityType::MOB, {1920, 800}, {50, 0}, {50, 50}, 1.5, "./assets/ennemy2.gif", "ennemy2");
        entity->container.movement_component->velocity.x = -5;
        entity->container.graphic_component->counter_sprites = 4;
        entities.push_back(entity);
        return entities;
    }

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
        QElapsedTimer *clock = new QElapsedTimer();
        int last_shoot = 1;
        clock->start();
        _systemManager->createGraphicSystem();
        _systemManager->createMovementSystem();
        _systemManager->createEventSystem();
        Entity *entity = new Entity(EntityType::BACKGROUND ,{0, 0},{0 , 0}, {1920, 1080}, 1.0, "./assets/backgournd2.jpg", "background");
        Entity *entity1 = new Entity(EntityType::BUTTON , {500, 500},{0, 0}, {500, 500}, 1.0, "./assets/button_play.png", "play");
        Entity *spaceShip = new Entity(EntityType::MAIN_PLAYER , {500, 500},{0, 0}, {500, 500}, 1.0, "./assets/r-typesheet42.gif", "spaceship");
        std::vector<Entity *> ennemy = ennemy2();
        
        Scene *scene = new Scene();
        scene->addEntity(entity);
        scene->addEntity(entity1);
        scene->addEntity(spaceShip);
        for (Entity *test_entity : ennemy) {
            scene->addEntity(test_entity);
        }
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
            if (clock->elapsed()/1000 >= last_shoot) {
                EnnemyShoot(_sceneManager->getCurrentScene());
                last_shoot++;
            }
            //sceneManager->getCurrentScene();
            _systemManager->updateGraphic(_sceneManager, clock->elapsed());
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