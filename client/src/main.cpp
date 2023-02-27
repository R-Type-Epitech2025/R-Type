#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include "ecs/SceneManager.hpp"
#include "ecs/Entity.hpp"
#include "ecs/Scene.hpp"
#include "systems/GraphicSystem.hpp"
#include "systems/MovementSystem.hpp"
#include <map>

void print()
{
    std::cout << "hey" << std::endl;
}

void shoot(std::vector<rtype::ComponentType> containers, rtype::SceneManager *sceneManager, sf::RenderWindow &window, rtype::Entity *entity)
{
    // create a bullet entity and add it to the scene
    rtype::Entity *bullet = new rtype::Entity(rtype::type::PROJECTILE, containers, 40, 40, 200, 100);
    bullet->container.graphic_component->createSprite("./assets/bullet.png", 32, 32, 1, rtype::Sprite_Direction::RIGHT);
    bullet->container.graphic_component->setSpritePosition(0, 0, true);
    bullet->container.graphic_component->setSize(200, 200);
    // Set the bullet position to the player position
    bullet->container.movement_component->pos.x = entity->container.movement_component->pos.x + 200;
    bullet->container.movement_component->pos.y = entity->container.movement_component->pos.y;
    sceneManager->getCurrentScene()->addEntity(bullet);
}

int main()
{
    std::cout << "window is open" << std::endl;
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "R-Type");
    window.setFramerateLimit(60);
    window.clear(sf::Color::Black);
    rtype::GraphicSystem *graphic = new rtype::GraphicSystem();
    rtype::MouvementSystem *mouvement = new rtype::MouvementSystem();
    std::vector<rtype::ComponentType> containers{rtype::ComponentType::GameComponent, rtype::ComponentType::GraphicComponent, rtype::ComponentType::MovemementComponent, rtype::ComponentType::EventComponent};
    rtype::Entity *entity = new rtype::Entity(rtype::type::MAIN_PLAYER, containers, 40, 40, 200, 100);
    entity->container.graphic_component->createSprite("./assets/ship.png", 128, 128, 1, rtype::Sprite_Direction::RIGHT);
    entity->container.graphic_component->setSpritePosition(0, 0, true);
    entity->container.graphic_component->setSize(200, 200);
    rtype::Entity *entity2 = new rtype::Entity(rtype::type::BUTTON, containers, 0, 200, 200, 100);
    entity2->container.graphic_component->createSprite("./assets/r-typesheet1.gif", 34, 14, 1, rtype::Sprite_Direction::RIGHT);
    entity2->container.graphic_component->setSpritePosition(534 / 2 - 68, 0, true);
    entity2->container.graphic_component->setSize(200, 100);
    rtype::Scene *scene = new rtype::Scene();
    scene->addEntity(entity);
    scene->addEntity(entity2);
    rtype::SceneManager *sceneManager = new rtype::SceneManager();
    sceneManager->addScene("first", scene);
    sceneManager->setScene("first");

    while (window.isOpen())
    {
        sf::Event event;
        rtype::Scene *scene = sceneManager->getCurrentScene();
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
                window.close();
            else if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Key::Space)
                    shoot(containers, sceneManager, window, entity);
            }
        }
        entity2->container.event_component->eventHandler(event, sf::Keyboard::Key::Space, rtype::Action::Shoot, window, &print);
        entity2->container.event_component->eventHandler(event, sf::Mouse::Button::Right, rtype::Action::Click, window, &print);
        mouvement->update(sceneManager, event);
        graphic->Update(sceneManager, 12, window);
        window.clear();
    }

    return 0;
}
