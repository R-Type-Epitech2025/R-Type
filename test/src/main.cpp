#include "Entity.hpp"
#include <SFML/Graphics.hpp>

//main loop :
// initialiser la scene
// timer
// event
// update
// transform
// graphic

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    Entity entity("pouet");
    entity.addComponent(std::make_shared<Sprite>("/home/Ary/Epitech/third_year/RTYPE/test/asset/test.png"));
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
                if (event.key.code == sf::Keyboard::Down)
                    entity.setPosition(entity.getX(), entity.getY() + 1);
                else if (event.key.code == sf::Keyboard::Up)
                    entity.setPosition(entity.getX(), entity.getY() - 1);
                else if (event.key.code == sf::Keyboard::Left)
                    entity.setPosition(entity.getX() - 1, entity.getY());
                else if (event.key.code == sf::Keyboard::Right)
                    entity.setPosition(entity.getX() + 1, entity.getY());
        }
        window.clear();
        entity.render(window);
        window.display();
    }
    return 0;
}