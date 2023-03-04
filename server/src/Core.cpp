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
    rtype::Entity *entity = new rtype::Entity(rtype::EntityType::MOB, {1000, std::rand()%1064}, {mobType, 0}, {32, 32}, 3.0, "./assets/sprites.png", "ennemy1");
    // entity->container.graphic_component->setSpritePosition(1000, 100);
    // entity->container.movement_component->velocity = 10;
    // entity->container.graphic_component->setPosition(entity->container.graphic_component->position.x -= entity->container.movement_component->velocity, entity->container.graphic_component->position.y);
    std::cout << "test2" << std::endl;
    return entity;
}

rtype::Core::Core() : _sceneManager(new rtype::SceneManager())
{
}

//, rtype::SceneManager *sceneManager
int rtype::Core::run(int argc, char **argv)
{
    sf::Event event;
    QCoreApplication game(argc, argv);
    std::srand(std::time(nullptr));
    QTimer *timer = new QTimer(&game);
    
    rtype::GraphicSystem *graphicSystem = new rtype::GraphicSystem();
    rtype::MovementSystem *movementSystem = new rtype::MovementSystem();
    rtype::EventSystem *eventSystem = new rtype::EventSystem();
    rtype::Entity *entity = new rtype::Entity(rtype::EntityType::BACKGROUND ,{0, 0},{0 , 0}, {1920, 1080}, 1.0, "./assets/backgournd2.jpg", "background");
    rtype::Entity *entity1 = new rtype::Entity(rtype::EntityType::BUTTON , {500, 500},{0, 0}, {500, 500}, 1.0, "./assets/button_play.png", "play");
    std::cout << "test3" << std::endl;
    rtype::Entity *spaceShipe = new rtype::Entity(rtype::EntityType::MAIN_PLAYER , {500, 500},{0, 0}, {500, 500}, 1.0, "./assets/r-typesheet42.gif", "spaceship");
    rtype::Entity *ennemy = spawnEnnemy();
    rtype::Scene *scene = new rtype::Scene();
    scene->addEntity(entity);
    scene->addEntity(entity1);
    scene->addEntity(spaceShipe);
    scene->addEntity(ennemy);
    eventSystem->createNewEvent("play", _sceneManager, "second", true, rtype::EventSystemType::CHANGESCENE, sf::Keyboard::Key::Escape);
    //rtype::Scene *scene2 = new rtype::Scene();
    //scene2->addEntity(entity);
    //scene2->addEntity(entity);

    _sceneManager->addScene("first" ,scene);
    //sceneManager->addScene("second" ,scene2);
    _sceneManager->setScene("first");
    //sceneManager, graphicSystem, movementSystem, &event, eventSystem
    QObject::connect(timer, &QTimer::timeout, [&]() {
        //std::vector<rtype::Entity*> entities = sceneManager->getCurrentScene()->get_entities();
        //rtype::Entity *player = NULL;
        //for (Entity *test_entity : entities){
        //    if (test_entity->_type == rtype::EntityType::MAIN_PLAYER)
        //        player = test_entity;
        //}

        while (_sceneManager->window.pollEvent(event)){
            if (event.type == sf::Event::Closed) 
                exit(0);
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                exit(0);
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                rtype::Entity *test = new rtype::Entity(rtype::EntityType::BULLET , {spaceShipe->container.movement_component->pos.y, spaceShipe->container.movement_component->pos.y},{0, 0}, {500, 500}, 1.0, "./assets/r-typesheet42.gif", "bullet");

//                rtype::Entity *test = new rtype::Entity(rtype::EntityType::BULLET , {spaceShipe->container.movement_component->pos.y, spaceShipe->container.movement_component->pos.y},{0, 0}, {500, 500}, {500, 500}, "./assets/test_image.jpg");
                _sceneManager->getCurrentScene()->addEntity(test);
                
            }
            
        }
        
        //sceneManager->getCurrentScene();
        graphicSystem->update(_sceneManager, 12);
        movementSystem->update(_sceneManager, event);
        eventSystem->update(_sceneManager, _sceneManager->window, event);

        // entity1->container.event_component->eventHandler(event, sf::Mouse::Button::Left, window, print);
    });
    timer->start(30);
    std::cout <<"test the end"<< std::endl;
    return game.exec();
}


rtype::Core::~Core()
{
} 
