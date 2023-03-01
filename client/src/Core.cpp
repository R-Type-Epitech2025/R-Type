/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Core
*/

#include "Core.hpp"
#include "SystemManager.hpp"
#include "iostream"

rtype::Core::Core()
{
}

int rtype::Core::run(int argc, char **argv, sf::RenderWindow &window)
{
    QCoreApplication game(argc, argv);
    QTimer *timer = new QTimer(&game);
    GraphicSystem *graphicSystem = new GraphicSystem();
    MovementSystem *movementSystem = new MovementSystem();
    SceneManager *sceneManager = new SceneManager();
    Entity *entity = new Entity(rtype::EntityType::BACKGROUND , 0, 0, 1920, 1080, "./assets/backgournd2.jpg");
    Entity *entity1 = new Entity(rtype::EntityType::BUTTON , 1000, 500, 100, 100, "./assets/button_play.png");
    Scene *scene = new Scene();
    scene->addEntity(entity);
    scene->addEntity(entity1);
    sceneManager->addScene("first" ,scene);
    sceneManager->setScene("first");


    QObject::connect(timer, &QTimer::timeout, [&window, sceneManager, graphicSystem, movementSystem]() {
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed) 
                exit(0);
        }
        sceneManager->getCurrentScene();
        graphicSystem->update(sceneManager, 12);
        movementSystem->update(sceneManager, event);
    });
    timer->start(30);
    std::cout <<"test the end"<< std::endl;
    return game.exec();
}


rtype::Core::~Core()
{
}
