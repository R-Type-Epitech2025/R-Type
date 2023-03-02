/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Core
*/

#include <ctime>

#include "Core.hpp"
#include "systems/SystemManager.hpp"
#include "iostream"

void print()
{
    std::cout << "test" << std::endl;
}

//à mettre dans le update du game system
rtype::Entity *spawnEnnemy()
{
    std::cout << "test1" << std::endl;
    int mobType = std::rand()%8 * 32;
    rtype::Entity *entity = new rtype::Entity(rtype::EntityType::MOB, {1000, std::rand()%1064}, {mobType, 0}, {32, 32}, {100, 100}, "./assets/sprites.png", "ennemy1");
    // entity->container.graphic_component->setSpritePosition(1000, 100);
    // entity->container.movement_component->velocity = 10;
    // entity->container.graphic_component->setPosition(entity->container.graphic_component->position.x -= entity->container.movement_component->velocity, entity->container.graphic_component->position.y);
    std::cout << "test2" << std::endl;
    return entity;
}

rtype::Core::Core()
{
}

int rtype::Core::run(int argc, char **argv, sf::RenderWindow &window)
{
    sf::Event event;
    QCoreApplication game(argc, argv);
    std::srand(std::time(nullptr));
    QTimer *timer = new QTimer(&game);
    system::GraphicSystem *graphicSystem = new system::GraphicSystem();
    system::MovementSystem *movementSystem = new system::MovementSystem();
    system::EventSystem *eventSystem = new system::EventSystem();
    SceneManager *sceneManager = new SceneManager();
    Entity *entity = new Entity(rtype::EntityType::BACKGROUND ,{0, 0},{0 , 0}, {1920, 1080}, {1920, 1080}, "./assets/backgournd2.jpg", "background");
    Entity *entity1 = new Entity(rtype::EntityType::BUTTON , {500, 500},{0, 0}, {500, 500}, {500, 500}, "./assets/button_play.png", "play");
    Entity *entity2 = new Entity(rtype::EntityType::BACKGROUND , {965, 500},{0, 0}, {500, 500}, {500, 500}, "./assets/backgournd2.jpg", "background2");
    Scene *scene = new Scene();
    scene->addEntity(entity);
    scene->addEntity(entity1);
    Scene *scene2 = new Scene();
    eventSystem->CreateNewEvent("play", sceneManager, "second", true, system::EventSystemType::CHANGESCENE, sf::Keyboard::Key::Space);
    scene2->addEntity(entity2);
    //test add ennemy
    scene->addEntity(spawnEnnemy());
    //test fin
    sceneManager->addScene("first" ,scene);
    sceneManager->setScene("first");
    sceneManager->addScene("second" ,scene2);


    QObject::connect(timer, &QTimer::timeout, [&window, sceneManager, graphicSystem, movementSystem, &event, eventSystem]() {
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed) 
                exit(0);
        }
        sceneManager->getCurrentScene();
        graphicSystem->Update(sceneManager, 12, window);
        movementSystem->update(sceneManager, event);
        eventSystem->update(sceneManager, window, event);
        // entity1->container.event_component->eventHandler(event, sf::Mouse::Button::Left, window, print);
    });
    timer->start(30);
    std::cout <<"test the end"<< std::endl;
    return game.exec();
}


rtype::Core::~Core()
{
}
