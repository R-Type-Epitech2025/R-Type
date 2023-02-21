/*
** EPITECH PROJECT, 2023
** client
** File description:
** Position
*/

#ifndef POSITION_HPP_
#define POSITION_HPP_

#include <SFML/Graphics.hpp>
#include "Position.hpp"

class Position {
    public:

        /**
         * @brief Construct a new Position object
         * 
         * @param x 
         * @param y 
         */
        Position(float x, float y);

        /**
         * @brief Construct a new Position object
         * 
         * @param _position 
         */
        Position(sf::Vector2f _position);
        
        /**
         * @brief Construct a new Position object
         * 
         * @param other 
         */
        Position(const Position & other);

        /**
         * @brief Construct a new Position object
         * 
         */
        Position();

        /**
         * @brief Destroy the Position object
         * 
         */
        ~Position();

        /**
         * @brief Get the Position object
         * 
         * @return sf::Vector2f 
         */
        sf::Vector2f getPosition() {return (_position);};

        /**
         * @brief set X position
         * 
         * @param x 
         */
        void setX(float x);

        /**
         * @brief set Y position
         * 
         * @param y 
         */
        void setY(float y);

    protected:
    private:
        sf::Vector2f _position;
};

#endif /* !POSITION_HPP_ */
