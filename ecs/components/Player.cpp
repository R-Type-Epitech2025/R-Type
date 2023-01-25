/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** player
*/
#include <SFML/graphics.hpp>
#include <iostream>


namespace rtype
{
    Player::Player()
    {
    }

    Player::Player(sf::Texture& TEMP_Texture)
    {
        _Sprite.setTexture(TEMP_Texture); //Set Sprite Texture
        _Sprite.setPosition(600 - 32, 350 - 32); //Set Sprite Position (Centre)
        _Sprite.setScale(1.5f, 1.5f); //Sprite Scale
        _Sprite.setTextureRect(sf::IntRect(_Source.x * 32, _Source.y * 32, 32, 32));
        _Speed = 0.20; //Player Speed
    }

    Player::~Player()
    {
    }

    void Player::moveUp()
    {
    }

    void Player::moveLeft()
    {
        std::cout << "moveLeft" << std::endl;
    }

    void Player::moveRight()
    {
        std::cout << "moveRight" << std::endl;
    }

    void Player::moveDown()
    {
        std::cout << "moveDown" << std::endl;
    }
}