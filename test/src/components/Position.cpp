#include "Position.hpp"

Position::Position(float _x, float _y):
    Component(Component::Type::POSITION)
{
    pos.x = _x;
    pos.y = _y;
    _isInitialized = true;
}

Position::Position(const Position &other):
    Component(Component::Type::POSITION)
{
    pos.x = other.pos.x;
    pos.y = other.pos.y;
    _isInitialized = true;
}

Position::Position(sf::Vector2f _pos):
    Component(Component::Type::POSITION)
{
    pos = _pos;
    _isInitialized = true;
}

Position::~Position()
{
}


void Position::setX(float _x)
{
    pos.x = _x;
}

void Position::setY(float _y)
{
    pos.y = _y;
}

sf::Vector2f Position::getPosition() 
{
    return (pos);
}

void Position::operator=(const Position &other)
{
    pos.x = other.pos.x;
    pos.y = other.pos.y;
}