/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Core
*/

#include "Core.hpp"
#include "systems/SystemManager.hpp"
#include "iostream"

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
    Entity *entity = new Entity(rtype::EntityType::MAIN_PLAYER , 0, 0, 10, 10, "../assets/pacman.png");
    Scene *scene = new Scene();
    scene->addEntity(entity);
    sceneManager->addScene("first" ,scene);
    sceneManager->setScene("first");


    QObject::connect(timer, &QTimer::timeout, [&window, sceneManager, graphicSystem, movementSystem]() {
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }
        sceneManager->getCurrentScene();
        graphicSystem->Update(sceneManager, 12, window);
        movementSystem->update(sceneManager, event);
    });
    timer->start(10);
    std::cout <<"test the end"<< std::endl;
    return game.exec();
}


rtype::Core::~Core()
{
}
