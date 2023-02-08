/*
** EPITECH PROJECT, 2023
** client
** File description:
** Sprite
*/

#ifndef SPRITE_HPP_
#define SPRITE_HPP_

#include <SFML/Graphics.hpp>
#include "Position.hpp"

class Sprite {
    public:
        /**
         * @brief Construct a new Sprite object
         * 
         * @param id 
         * @param angle 
         */
        Sprite(int id, float angle = 0, sf::IntRect = sf::IntRect(0, 0, 0, 0));

        /**
         * @brief Destroy the Sprite object
         * 
         */
        ~Sprite();

        /**
         * @brief Set the sprite object
         * 
         */
        void Setsprite();

        /**
         * @brief Get the sprite object
         * 
         */
        void GetSprite();

        /**
         * @brief Set rectangle of the sprite
         * 
         * @param rect 
         */
        void SetRect(sf::IntRect);

        /**
         * @brief Get the sprite rectangle
         * 
         */
        void GetRect();

        /**
         * @brief Set the Angle of the sprite
         * 
         */
        void SetAngle(float);

        /**
         * @brief Get the Angle of the sprite
         *
        */
        void getAngle();

        /**
         * @brief Set the Id of the sprite
         * 
         */
        void SetId(int);

    protected:
    private:
};

#endif /* !SPRITE_HPP_ */
