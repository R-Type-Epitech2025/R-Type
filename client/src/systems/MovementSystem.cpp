/*
** EPITECH PROJECT, 2023
** client
** File description:
** MovementSystem
*/

#include "MovementSystem.hpp"
#include <iostream>

namespace rtype{
    MovementSystem::MovementSystem(QObject *parent) : QObject(parent)
    {
        std::cout << "MovementSystem created" << std::endl;
    }

    // MovementSystem::~MovementSystem(){
    // }
    
    void MovementSystem::update(SceneManager *Manager, sf::Event &event){
        //std::cout << "position updated" << std::endl;

        Scene *Scene = Manager->getCurrentScene();

        for (Entity *entity : Scene->get_entities()){
            if (entity->container.movement_component != nullptr) {
                if (event.type == sf::Event::KeyPressed && entity->container.movement_component->is_linked() == true) {   
                    if (event.key.code == sf::Keyboard::Up) {
                        std::cout << "up" << std::endl;
                        emit sendMovePlayer(DIRECTION::UP);
                    } else if (event.key.code == sf::Keyboard::Down){
                        std::cout << "down" << std::endl;
                        emit sendMovePlayer(DIRECTION::DOWN);
                    } else if (event.key.code == sf::Keyboard::Left){
                        std::cout << "left" << std::endl;
                        emit sendMovePlayer(DIRECTION::LEFT);
                    }
                    else if (event.key.code == sf::Keyboard::Right){
                        std::cout << "right" << std::endl;
                        emit sendMovePlayer(DIRECTION::RIGHT);
                    }
                }
            }
            if (entity->_type == EntityType::TEXT && entity->container.graphic_component->getIsWritable() == true) {
                if (event.type == sf::Event::TextEntered && event.text.unicode < 128 && sf::Event::KeyReleased) {
                    entity->container.graphic_component->setInputText(entity->container.graphic_component->getInputText() + static_cast<char>(event.text.unicode));
                }
            }
            if (entity != nullptr && entity->container.movement_component != nullptr) {
                entity->container.movement_component->applyVelocity();
                entity->container.movement_component->checkParallax();
            }

        }
    }
}