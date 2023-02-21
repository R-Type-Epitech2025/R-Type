/*
** EPITECH PROJECT, 2023
** client
** File description:
** Hitbox
*/

#ifndef HITBOX_HPP_
#define HITBOX_HPP_

#include <SFML/Graphics.hpp>

class Hitbox {
    public:
        /**
         * @brief Construct a new Hitbox object
         * 
         */
        Hitbox(sf::IntRect = sf::IntRect(0, 0, 0, 0));

        /**
         * @brief Destroy the Hitbox object
         * 
         */
        ~Hitbox();

        /**
         * @brief Set the Hitbox rectangle
         * 
         * @param sf::IntRect
         */
        void setRect(sf::IntRect);

        /**
         * @brief Get the Hitbox rectangle
         * 
         */
        void getRect() const;

    protected:
    private:
};

#endif /* !HITBOX_HPP_ */
