/*
** EPITECH PROJECT, 2023
** client
** File description:
** MovementSystem
*/

#include "systems/MovementSystem.hpp"
#include <iostream>

namespace rtype{
    MovementSystem::MovementSystem(QObject *parent) : QObject(parent)
    {
        std::cout << "MovementSystem created" << std::endl;
    }

    // MovementSystem::~MovementSystem(){
    // }
    
    void MovementSystem::update(rtype::SceneManager *Manager, sf::Event &event){
        //std::cout << "position updated" << std::endl;

        Scene *Scene = Manager->getCurrentScene();

        for (Entity *entity : Scene->get_entities()){
            if (entity->_type == MAIN_PLAYER && entity->container.movement_component->is_linked() == false)
                std::cout << "dsfsdfsd" << std::endl;
            if (entity->container.movement_component != NULL){
                if (event.type == sf::Event::KeyPressed && entity->container.movement_component->is_linked() == true){   
                    if (event.key.code == sf::Keyboard::Up) {
                        entity->set_direction(rtype::DIRECTION::UP);
                        entity->container.movement_component->pos.y -= 5;
                        emit sendMovePlayer(rtype::DIRECTION::UP);
                    } else if (event.key.code == sf::Keyboard::Down){
                        entity->set_direction(rtype::DIRECTION::DOWN);
                        entity->container.movement_component->pos.y += 5;
                        emit sendMovePlayer(rtype::DIRECTION::DOWN);
                    } else if (event.key.code == sf::Keyboard::Left){
                        entity->set_direction(rtype::DIRECTION::LEFT);
                        entity->container.movement_component->pos.x -= 5;
                        emit sendMovePlayer(rtype::DIRECTION::LEFT);
                    }
                    else if (event.key.code == sf::Keyboard::Right){
                        entity->set_direction(rtype::DIRECTION::RIGHT);
                        entity->container.movement_component->pos.x += 5;
                        emit sendMovePlayer(rtype::DIRECTION::RIGHT);
                    }
                }
                entity->container.movement_component->pos.y += entity->container.movement_component->velocity.y;
                entity->container.movement_component->pos.x += entity->container.movement_component->velocity.x;
            }   
        }
    }
}