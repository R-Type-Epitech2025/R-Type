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
        Velocity(float x, float y);
        Velocity(sf::Vector2f _velocity);
        ~Velocity();

        void setX(float x) { _velocity.x = x; };
        void setY(float y) { _velocity.y = y; };
    protected:
    private:
        sf::Vector2f _velocity;
};

} // namespace component
    
#endif /* !VELOCITY_HPP_ */
