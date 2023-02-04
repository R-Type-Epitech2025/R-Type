#include "Text.hpp"

Text::Text(std::string pathFont, std::string string, int size, sf::Color color):
    Component(Component::Type::TEXT)
{
    text.setFont(font);
    text.setString(string);
    text.setCharacterSize(size);
    text.setColor(color);
}

Text::~Text()
{
}

void Text::printText(sf::RenderWindow *window, Position position)
{
    sf::Vector2f pos(position.getPosition());

    text.setPosition(pos);
    window->draw(text);
}