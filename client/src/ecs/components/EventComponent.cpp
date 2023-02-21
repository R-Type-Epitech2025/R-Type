/*
** EPITECH PROJECT, 2023
** Archi
** File description:
** EventComponent
*/

#include "ecs/components/EventComponent.hpp"
#include <SFML/Graphics.hpp>


namespace rtype{
    EventComponent::EventComponent()
    {
    }

    EventComponent::~EventComponent()
    {
    }

    void shoot(sf::RenderWindow& window) {
    sf::Clock clock;
    rtype::Entity *entity = new rtype::Entity(rtype::type::PROJECTILE);
    entity->add_Container(rtype::ComponentType::GameComponent);
    entity->add_Container(rtype::ComponentType::GraphicComponent);
    entity->add_Container(rtype::ComponentType::MovemementComponent);
    entity->add_Container(rtype::ComponentType::EventComponent);
    entity->container.graphic_component->createSprite("../../assets/r-typesheet1.gif", 34, 14, 1, rtype::Sprite_Direction::RIGHT);
    entity->container.graphic_component->setSpritePosition(200, 0, true);
    entity->container.graphic_component->setSize(200, 100);
    entity->container.movement_component->pos.x = 0;
    entity->container.movement_component->pos.y = 100;
    sf::CircleShape projectile(10.f);
    projectile.setFillColor(sf::Color::Red);
    projectile.setPosition(window.getSize().x / 2.f, window.getSize().y - projectile.getRadius());
    sf::Vector2f velocity(0.f, -500.f);
    while (window.isOpen()) {
        sf::Time elapsed = clock.restart();
        float deltaTime = elapsed.asSeconds();
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        projectile.move(velocity * deltaTime);
        window.clear();
        window.draw(projectile);
        window.display();
        if (projectile.getPosition().y < -projectile.getRadius())
            window.close(); 
    }
}


    void EventComponent::eventHandler(sf::RenderWindow& window, sf::Event event, sf::Keyboard::Key key, rtype::Action action, void(*direction)()) {
        if (event.type == sf::Event::KeyPressed){   
            if (event.key.code == key) {
                if (action == rtype::Action::Click) 
                    direction();
                if (action == rtype::Action::Shoot)
                    shoot(window);
            }    
        }
    }
}