
#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include "../Entity.hpp"
#include <QtCore>


namespace rtype {
    class MouvementManager : public QObject {
    public:
        enum Mouvement_Keyboard {
            Up = sf::Keyboard::Up ,
            Down = sf::Keyboard::Down,
            Left = sf::Keyboard::Left,
            Right = sf::Keyboard::Right
        };
        MouvementManager();
        bool SetNewPosition(Mouvement_Keyboard mouv);
        bool LinkKeybordPosition(sf::Event &event, std::shared_ptr<rtype::Entity> entity);
    private :
    };
}