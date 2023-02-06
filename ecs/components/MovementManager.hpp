
#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include "../Entity.hpp"

namespace rtype {
    class MouvementManager {
    public:
    enum Mouvement {
            Up = sf::Keyboard::Up ,
            Down = sf::Keyboard::Down,
            Left = sf::Keyboard::Left,
            Right = sf::Keyboard::Right
        };
        MouvementManager();
        bool SetNewPosition(Mouvement mouv);
        bool LinkKeybordPosition(sf::Event &event, std::shared_ptr<rtype::Entity> entity);
    private :

    };
}