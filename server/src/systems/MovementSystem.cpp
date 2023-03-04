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
        // move all entities with a movement component
    }

    void MovementSystem::onSendMovePlayer(quint32 id, DIRECTION dir)
    {
        std::cout << "Player " << id << " moved ";
        if (dir == DIRECTION::UP)
            std::cout << "UP" << std::endl;
        else if (dir == DIRECTION::DOWN)
            std::cout << "DOWN" << std::endl;
        else if (dir == DIRECTION::LEFT)
            std::cout << "LEFT" << std::endl;
        else if (dir == DIRECTION::RIGHT)
            std::cout << "RIGHT" << std::endl;
        else
            std::cout << "UNKNOWN" << std::endl;
        // emit sendMovePlayer(id, dir);
    }
}