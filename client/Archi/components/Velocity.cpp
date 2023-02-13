/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Velocity
*/

#include "Velocity.hpp"


rtype::Velocity::Velocity(float x, float y)
{
    _velocity.x = x;
    _velocity.y = y;
}

rtype::Velocity::Velocity(sf::Vector2f _velocity)
{
    this->_velocity = _velocity;
}

rtype::Velocity::~Velocity()
{
}

