#pragma once

#include "Component.hpp"
#include <SFML/Graphics.hpp>

class Position : public Component 
{
    public:
        Position(float _x, float _y);
        Position(const Position &other);
        Position(sf::Vector2f _pos);
        ~Position();

        void setX(float _x);
        void setY(float _y);
        sf::Vector2f getPosition() {return (pos);};
        void operator=(const Position &other);
    private:
        sf::Vector2f pos;
};