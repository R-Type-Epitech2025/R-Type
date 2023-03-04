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
            if (entity->container.movement_component != NULL){
                if (event.type == sf::Event::KeyPressed && entity->container.movement_component->is_linked() == true){   
                    if (event.key.code == sf::Keyboard::Up) {
                        std::cout << "up" << std::endl;
                        emit sendMovePlayer(rtype::DIRECTION::UP);
                    } else if (event.key.code == sf::Keyboard::Down){
                        std::cout << "down" << std::endl;
                        emit sendMovePlayer(rtype::DIRECTION::DOWN);
                    } else if (event.key.code == sf::Keyboard::Left){
                        std::cout << "left" << std::endl;
                        emit sendMovePlayer(rtype::DIRECTION::LEFT);
                    }
                    else if (event.key.code == sf::Keyboard::Right){
                        std::cout << "right" << std::endl;
                        emit sendMovePlayer(rtype::DIRECTION::RIGHT);
                    }
                }
            }   
        }
    }
}