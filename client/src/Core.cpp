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

void fire(rtype::Scene **scene, rtype::Entity *spaceship)
{
    rtype::Entity *bullet = new rtype::Entity(rtype::EntityType::BULLET, {spaceship->container.movement_component->pos.x + 250, spaceship->container.movement_component->pos.y + 250}, {0, 0}, {500, 500}, {500, 500}, "./assets/r-typesheet42.gif");
    (*scene)->addEntity(bullet);
}

rtype::Core::Core()
{
}

int rtype::Core::run(int argc, char **argv, sf::RenderWindow &window)
{
    QCoreApplication game(argc, argv);
    QTimer *timer = new QTimer(&game);
    rtype::system::GraphicSystem *graphicSystem = new rtype::system::GraphicSystem();
    rtype::system::MovementSystem *movementSystem = new rtype::system::MovementSystem();
    rtype::SceneManager *sceneManager = new rtype::SceneManager();
    rtype::Entity *entity = new rtype::Entity(rtype::EntityType::BACKGROUND ,{0, 0},{0 , 0}, {1920, 1080}, {1920, 1080}, "./assets/backgournd2.jpg");
    rtype::Entity *spaceship = new rtype::Entity(rtype::EntityType::MAIN_PLAYER , {965, 500},{0, 0}, {166, 80}, {500, 500}, "./assets/r-typesheet42.gif");
    rtype::Scene *scene = new rtype::Scene();
    scene->addEntity(entity);
    scene->addEntity(spaceship);
    sceneManager->addScene("first" ,scene);
    sceneManager->setScene("first");
    QObject::connect(timer, &QTimer::timeout, [&window, sceneManager, graphicSystem, movementSystem, spaceship]() {
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed) 
                exit(0);
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                exit(0);
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                rtype::Entity *test = new rtype::Entity(rtype::EntityType::BULLET , {spaceship->container.movement_component->pos.x, spaceship->container.movement_component->pos.y},{0, 0}, {500, 500}, {500, 500}, "./assets/test_image.jpg");
                sceneManager->getCurrentScene()->addEntity(test);
                
            }
        }
        
        sceneManager->getCurrentScene();
        graphicSystem->Update(sceneManager, 12, window);
        movementSystem->update(sceneManager, event);
        spaceship->container.event_component->eventHandler(event, sf::Mouse::Button::Left, window, print);

    });
    timer->start(30);
    std::cout <<"test the end"<< std::endl;
    return game.exec();
}


rtype::Core::~Core()
{
}
