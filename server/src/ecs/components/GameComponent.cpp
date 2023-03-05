/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** GameComponent
*/
#include "GameComponent.hpp"
#include <QtNetwork>


namespace rtype{
    GameComponent::GameComponent(int cooldown, int last_shot, int health, int damage) : cooldown(cooldown), last_shot(last_shot), health(health), damage(damage)
    {
    }

    GameComponent::~GameComponent()
    {
    }
}
