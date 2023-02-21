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
        void init(SceneManager&) override;
        void Update(SceneManager&, int deltaTime) override;
        void destroy(SceneManager&) override;
        void loadEntity() override;
        void unloadEntity() override;
    private :
    };
}