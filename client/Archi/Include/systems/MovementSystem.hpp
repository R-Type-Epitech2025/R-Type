#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include "../SceneManager.hpp"
#include "../Entity.hpp"

namespace rtype {
    class MouvementSystem {
    public:
       MouvementSystem();
       ~MouvementSystem();
        void update(SceneManager *Manager, sf::Event event);
    private :
        bool _link;

    };
}