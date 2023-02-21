#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include "ecs/SceneManager.hpp"
#include "ecs/Entity.hpp"
#include "ecs/Scene.hpp"
#include "systems/GraphicSystem.hpp"
#include "systems/MovementSystem.hpp"
#include <map>




void print(){
    std::cout << "hey" << std::endl;
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "My Game");
    window.setFramerateLimit(60);
    window.clear(sf::Color::Black);
    rtype::GraphicSystem *graphic = new rtype::GraphicSystem();
    rtype::MouvementSystem *mouvement = new rtype::MouvementSystem();
    rtype::Entity *entity = new rtype::Entity(rtype::type::MAIN_PLAYER);
    entity->add_Container(rtype::ComponentType::GameComponent);
    entity->add_Container(rtype::ComponentType::GraphicComponent);
    entity->add_Container(rtype::ComponentType::MovemementComponent);
    entity->container.graphic_component->createSprite("./assets/r-typesheet1.gif", 34, 14, 1, rtype::Sprite_Direction::RIGHT);
    entity->container.graphic_component->setSpritePosition(534/2 - 68, 0, true);
    entity->container.graphic_component->setSize(200, 100);
    entity->container.movement_component->pos.x = 0;
    entity->container.movement_component->pos.y = 0;
    rtype::Entity *entity2 = new rtype::Entity(rtype::type::BUTTON);
    entity2->add_Container(rtype::ComponentType::GameComponent);
    entity2->add_Container(rtype::ComponentType::GraphicComponent);
    entity2->add_Container(rtype::ComponentType::MovemementComponent);
    entity2->add_Container(rtype::ComponentType::EventComponent);
    entity2->container.graphic_component->createSprite("./assets/r-typesheet1.gif", 34, 14, 1, rtype::Sprite_Direction::RIGHT);
    entity2->container.graphic_component->setSpritePosition(534/2 - 68, 0, true);
    entity2->container.graphic_component->setSize(200, 100);
    entity2->container.movement_component->pos.x = 0;
    entity2->container.movement_component->pos.y = 100;
    rtype::Scene *scene = new rtype::Scene();
    scene->addEntity(entity);
    scene->addEntity(entity2);
    rtype::SceneManager *sceneManager = new rtype::SceneManager();
    sceneManager->addScene("first", scene);
    sceneManager->setScene("first");

    while(window.isOpen()){
        sf::Event event;
        rtype::Scene *scene = sceneManager->getCurrentScene();
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }
        entity2->container.event_component->eventHandler(window, event, sf::Keyboard::Up, rtype::Action::Click, &print);
        entity->container.event_component->eventHandler(window, event, sf::Keyboard::Space, rtype::Action::Shoot);
        mouvement->update(sceneManager, event);
        graphic->Update(sceneManager, 12, window);
        window.clear();
    }

    return 0;
}



