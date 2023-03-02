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

//void fire(rtype::Scene **scene, rtype::Entity *spaceship)
//{
//    rtype::Entity *bullet = new rtype::Entity(rtype::EntityType::BULLET, {spaceship->container.movement_component->pos.x + 250, spaceship->container.movement_component->pos.y + 250}, {0, 0}, {500, 500}, {500, 500}, "./assets/r-typesheet42.gif");
//    (*scene)->addEntity(bullet);
//}

rtype::Core::Core()
{
}

int rtype::Core::run(int argc, char **argv, rtype::SceneManager *sceneManager)
{
    sf::Event event;
    QCoreApplication game(argc, argv);
    QTimer *timer = new QTimer(&game);
    
    rtype::GraphicSystem *graphicSystem = new rtype::GraphicSystem();
    rtype::MovementSystem *movementSystem = new rtype::MovementSystem();
    rtype::EventSystem *eventSystem = new rtype::EventSystem();
    rtype::Entity *entity = new rtype::Entity(rtype::EntityType::BACKGROUND ,{0, 0},{0 , 0}, {1920, 1080}, {1920, 1080}, "./assets/backgournd2.jpg", "background");
    rtype::Entity *entity1 = new rtype::Entity(rtype::EntityType::BUTTON , {500, 500},{0, 0}, {500, 500}, {500, 500}, "./assets/button_play.png", "play");
    rtype::Entity *spaceShipe = new rtype::Entity(rtype::EntityType::MAIN_PLAYER , {500, 500},{0, 0}, {500, 500}, {500, 500}, "./assets/r-typesheet42.gif", "spaceship");
    
    rtype::Scene *scene = new rtype::Scene();
    scene->addEntity(entity);
    scene->addEntity(entity1);
    scene->addEntity(spaceShipe);
    eventSystem->createNewEvent("play", sceneManager, "second", true, rtype::EventSystemType::CHANGESCENE, sf::Keyboard::Key::Escape);
    rtype::Scene *scene2 = new rtype::Scene();
    scene2->addEntity(entity);
    scene2->addEntity(entity);

    sceneManager->addScene("first" ,scene);
    sceneManager->addScene("second" ,scene2);
    sceneManager->setScene("first");

    QObject::connect(timer, &QTimer::timeout, [sceneManager, graphicSystem, movementSystem, &event, eventSystem]() {
        while (sceneManager->window.pollEvent(event)){
            if (event.type == sf::Event::Closed) 
                exit(0);
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                exit(0);
            //if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
            //    rtype::Entity *test = new rtype::Entity(rtype::EntityType::BULLET , {spaceship->container.movement_component->pos.x, spaceship->container.movement_component->pos.y},{0, 0}, {500, 500}, {500, 500}, "./assets/test_image.jpg");
            //    sceneManager->getCurrentScene()->addEntity(test);
            //    
            //}
        }
        
        //sceneManager->getCurrentScene();
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
