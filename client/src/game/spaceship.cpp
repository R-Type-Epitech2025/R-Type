#include "Entity.hpp"
#include "Scene.hpp"

namespace rtype {
    Entity *initSpaceShip() {
        Entity *spaceship = new Entity(rtype::EntityType::PLAYER, {0, 0}, {0, 0}, {0, 0}, {0, 0}, "assets/spritesheet.png");
        
        return spaceship;
    }

    Scene *initScene() {
        Scene *scene = new Scene();
        scene->addEntity(initSpaceShip());
        return scene;
    }

    Entity *bullet(int x, int y) {
        Entity *bullet = new Entity(rtype::EntityType::BULLET, {x, y}, {0, 0}, {0, 0}, {0, 0}, "assets/spritesheet.png");
        return bullet;
    }
}