#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include "SceneManager.hpp"
#include "Entity.hpp"
#include <QObject>

namespace rtype {
    namespace system {

        class MovementSystem: public QObject {
            Q_OBJECT
        public:
        MovementSystem();
        ~MovementSystem();
            void update(rtype::SceneManager *Manager, sf::Event event);
        private :
            bool _link;

        signals:
            void sendMovePlayer(DIRECTION dir);

        };
    }
}