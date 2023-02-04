#pragma once
#include "IComponent.hpp"
#include <SFML/Graphics.hpp>

class Sprite : public IComponent
{
    public:
        Sprite(const std::string &path);
        ~Sprite() override = default;

        void Render(sf::RenderWindow &window);
        void setPosition(float x, float y);
        float getX() const;
        float getY() const;
    private:
        sf::Texture _texture;
        sf::Sprite _sprite;
};