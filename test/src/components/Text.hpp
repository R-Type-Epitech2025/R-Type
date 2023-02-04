#include "Component.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <Position.hpp>

class Text : public Component
{
    public:
        Text(std::string pathFont, std::string string, int size, sf::Color color);
        ~Text();

        void printText(sf::RenderWindow *win, Position pos);
    private:
        sf::Text text;
        sf::Font font;
};