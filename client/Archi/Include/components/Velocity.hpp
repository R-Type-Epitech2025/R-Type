/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Velocity
*/

#ifndef VELOCITY_HPP_
#define VELOCITY_HPP_

#include <SFML/Graphics.hpp>
#include "IComponent.hpp"

namespace rtype {
        class Velocity {
    public:
        /**
         * @brief Construct a new Velocity object
         * 
         * @param x 
         * @param y 
         */
        Velocity(float x, float y);

        /**
         * @brief Construct a new Velocity object
         * 
         * @param _velocity 
         */
        Velocity(sf::Vector2f _velocity);

        /**
         * @brief Destroy the Velocity object
         * 
         */
        ~Velocity();

        /**
         * @brief Set the X position
         * 
         * @param x 
         */
        void setX(float x) { _velocity.x = x; };

        /**
         * @brief Set the Y position
         * 
         * @param y 
         * 
         */
        void setY(float y) { _velocity.y = y; };
    protected:
    private:
        sf::Vector2f _velocity;
};

} // namespace component
    
#endif /* !VELOCITY_HPP_ */