// #include <SFML/Graphics.hpp>
// #include <iostream>
// #include <memory>
// #include "../include/ecs/SceneManager.hpp"
// #include "Entity.hpp"
// #include "Scene.hpp"
// #include "GraphicSystem.hpp"
// #include "MovementSystem.hpp"
// #include <map>
#include "Core.hpp"


int main(int argc, char* argv[]) {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "My Game");
void print()
{
    std::cout << "hey" << std::endl;
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "R-Type");
    window.setFramerateLimit(60);
    window.clear(sf::Color::Black);
    rtype::Core core;
    core.run(argc, argv, window);
    rtype::GraphicSystem *graphic = new rtype::GraphicSystem();
    rtype::MouvementSystem *mouvement = new rtype::MouvementSystem();
    rtype::Entity *entity = new rtype::Entity(rtype::type::BUTTON);
    entity->add_Container(rtype::ComponentType::GameComponent);
    entity->add_Container(rtype::ComponentType::GraphicComponent);
    entity->add_Container(rtype::ComponentType::MovemementComponent);
    entity->container.graphic_component->createSprite("./assets/button_play.png", 331, 329, 1, rtype::Sprite_Direction::RIGHT);
    entity->container.graphic_component->setSpritePosition(0, 0, true);
    entity->container.graphic_component->setSize(331, 329);
    entity->container.movement_component->pos = {10, 10};
    rtype::Entity *entity2 = new rtype::Entity(rtype::type::BUTTON);
    entity2->add_Container(rtype::ComponentType::GameComponent);
    entity2->add_Container(rtype::ComponentType::GraphicComponent);
    entity2->add_Container(rtype::ComponentType::MovemementComponent);
    entity2->add_Container(rtype::ComponentType::EventComponent);
    entity2->container.graphic_component->createSprite("./assets/button_settings.png", 176, 175, 1, rtype::Sprite_Direction::RIGHT);
    entity2->container.graphic_component->setSpritePosition(0, 0, true);
    entity2->container.graphic_component->setSize(176, 175);
    entity2->container.movement_component->pos = {30, 30};
    rtype::Scene *scene = new rtype::Scene();
    scene->addEntity(entity);
    scene->addEntity(entity2);
    rtype::SceneManager *sceneManager = new rtype::SceneManager();
    sceneManager->addScene("menu", scene);
    sceneManager->setScene("menu");

    while (window.isOpen())
    {
        sf::Event event;
        rtype::Scene *scene = sceneManager->getCurrentScene();
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        entity2->container.event_component->eventHandler(event, sf::Keyboard::Up, rtype::Action::Click, &print);
        mouvement->update(sceneManager, event);
        graphic->Update(sceneManager, 12, window);
        window.clear();
    }

    return 0;
}