/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Core
*/

#include "Core.hpp"
#include "SystemManager.hpp"
#include "iostream"

void print()
{
    std::cout << "test" << std::endl;
}

rtype::Core::Core()
{
}

int rtype::Core::run(int argc, char **argv, SceneManager *sceneManager)
{
    sf::Event event;
    QCoreApplication game(argc, argv);
    QTimer *timer = new QTimer(&game);
    
    GraphicSystem *graphicSystem = new GraphicSystem();
    MovementSystem *movementSystem = new MovementSystem();
    EventSystem *eventSystem = new EventSystem();
    Entity *entity = new Entity(rtype::EntityType::BACKGROUND ,{0, 0},{0 , 0}, {1920, 1080}, {1920, 1080}, "./assets/backgournd2.jpg", "background");
    Entity *entity1 = new Entity(rtype::EntityType::BUTTON , {500, 500},{0, 0}, {500, 500}, {500, 500}, "./assets/button_play.png", "play");
    
    Scene *scene = new Scene();
    
    scene->addEntity(entity);
    scene->addEntity(entity1);
    eventSystem->createNewEvent("play", sceneManager, "second", true, rtype::EventSystemType::CHANGESCENE, sf::Keyboard::Key::Escape);
    Scene *scene2 = new Scene();
    scene2->addEntity(entity);
    scene2->addEntity(entity);

    sceneManager->addScene("first" ,scene);
    sceneManager->addScene("second" ,scene2);
    sceneManager->setScene("first");

    QObject::connect(timer, &QTimer::timeout, [sceneManager, graphicSystem, movementSystem, &event, eventSystem]() {
        while (sceneManager->window.pollEvent(event)){
            if (event.type == sf::Event::Closed) 
                exit(0);
        }
        sceneManager->getCurrentScene();
        graphicSystem->update(sceneManager, 12);
        movementSystem->update(sceneManager, event);
        eventSystem->update(sceneManager, sceneManager->window, event);

        // entity1->container.event_component->eventHandler(event, sf::Mouse::Button::Left, window, print);
    });
    timer->start(30);
    std::cout <<"test the end"<< std::endl;
    return game.exec();
}


rtype::Core::~Core()
{
}
