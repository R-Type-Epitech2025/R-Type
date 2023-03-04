/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** DeviceSystem
*/

#include "DeviceSystem.hpp"

DeviceSystem::DeviceSystem()
{
}

DeviceSystem::~DeviceSystem()
{
}

void DeviceSystem::getinput()
{
    sf::Event event;
            if (event.key.code == sf::Keyboard::Escape)
                ESCAPE;
            if (event.key.code == sf::Keyboard::Left)
                LEFT;
            if (event.key.code == sf::Keyboard::Right)
                RIGHT;
            if (event.key.code == sf::Keyboard::Up)
                UP;
            if (event.key.code == sf::Keyboard::Down)
                DOWN;
            if (event.key.code == sf::Keyboard::Space)
                SHOOT;
        }
