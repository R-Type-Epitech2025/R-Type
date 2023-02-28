/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Core
*/

#include "Core.hpp"
#include "systems/SystemManager.hpp"
#include "iostream"

void print()
{
    std::cout << "test" << std::endl;
}

rtype::Core::Core()
{
}

int rtype::Core::run(int argc, char **argv, sf::RenderWindow &window)
{
    QCoreApplication game(argc, argv);
    QTimer *timer = new QTimer(&game);
    system::GraphicSystem *graphicSystem = new system::GraphicSystem();
    system::MovementSystem *movementSystem = new system::MovementSystem();
    SceneManager *sceneManager = new SceneManager();
    Entity *entity = new Entity(rtype::EntityType::BACKGROUND ,{0, 0},{0 , 0}, {1920, 1080}, {1920, 1080}, "./assets/backgournd2.jpg");
    Entity *entity1 = new Entity(rtype::EntityType::BUTTON , {965, 500},{0, 0}, {500, 500}, {500, 500}, "./assets/button_play.png");
    Entity *entity2 = new Entity(rtype::EntityType::BACKGROUND , {965, 500},{0, 0}, {500, 500}, {500, 500}, "./assets/backgournd2.jpg");
    Scene *scene = new Scene();
    scene->addEntity(entity);
    scene->addEntity(entity1);
    Scene *scene2 = new Scene();
    scene2->addEntity(entity2);
    sceneManager->addScene("first" ,scene);
    sceneManager->setScene("first");
    sceneManager->addScene("second" ,scene2);


    QObject::connect(timer, &QTimer::timeout, [&window, sceneManager, graphicSystem, movementSystem, entity1]() {
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed) 
                exit(0);
        }
        sceneManager->getCurrentScene();
        graphicSystem->Update(sceneManager, 12, window);
        movementSystem->update(sceneManager, event);
        entity1->container.event_component->eventHandler(event, sf::Mouse::Button::Left, window, "second", sceneManager);
    });
    timer->start(30);
    std::cout <<"test the end"<< std::endl;
    return game.exec();
}


rtype::Core::~Core()
{
}
