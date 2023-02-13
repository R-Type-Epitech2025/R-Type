#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#include <QtCore>
#include "ISystem.hpp"

namespace rtype {
    class MouvementSystem : public ISystem {
    public:
       MouvementSystem();
       ~MouvementSystem();
    private :
    };
}