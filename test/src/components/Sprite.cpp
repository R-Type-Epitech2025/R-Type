#include "Sprite.hpp"

Sprite::Sprite(const std::string &path)
{
    _texture.loadFromFile(path);
    _sprite.setTexture(_texture);
}

void Sprite::Render(sf::RenderWindow &window)
{
    window.draw(_sprite);
}

void Sprite::setPosition(float x, float y)
{
    _sprite.setPosition(x, y);
}

float Sprite::getX() const
{
    return _sprite.getPosition().x;
}

float Sprite::getY() const
{
    return _sprite.getPosition().y;
}
