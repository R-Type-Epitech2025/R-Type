/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** MovementSystem
*/
#include <SFML/GRAPHICS/sprite.hpp>
#include "MovementSystem.hpp"

namespace rtype {
    MovementSystem::MovementSystem()
    { 
    }


    MovementSystem::~MovementSystem()
    {
    }

    void MovementSystem::moveUp(sf::Vector2i _Source, _Sprite, _Speed)
    {
        _Source.y = Up;
        _Sprite.move(0, -_Speed);

    }

    void MovementSystem::moveLeft(sf::Vector2i _Source, _Sprite, _Speed)
    {
        _Source.y = Left;
        _Sprite.move(-_Speed, 0);
    }

    void MovementSystem::moveRight( sf::Vector2i _Source, _Sprite, _Speed)
    {
        _Source.y = Right;
        _Sprite.move(_Speed, 0);

    }

    void MovementSystem::moveDown( sf::Vector2i _Source, _Sprite, _Speed)
    {
        _Source.y = Down;
        _Sprite.move(0, _Speed);
    }
}