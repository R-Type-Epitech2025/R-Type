/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** GameComponent
*/
#include "GameComponent.hpp"

namespace rtype{
    GameComponent::GameComponent(int cooldown = 0, int last_shot, int health = 1, int damage = 1) : cooldown(cooldown), health(health), damage(damage)
    {
    }

    GameComponent::~GameComponent()
    {
    }
}
