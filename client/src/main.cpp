// #include <SFML/Graphics.hpp>
// #include <iostream>
// #include <memory>
// #include "../include/ecs/SceneManager.hpp"
// #include "Entity.hpp"
// #include "Scene.hpp"
// #include "GraphicSystem.hpp"
// #include "MovementSystem.hpp"
// #include <map>
#include "Core.hpp"


int main(int argc, char* argv[]) {
    rtype::Core core;
    rtype::SceneManager *scenemanager = new rtype::SceneManager();
    core.run(argc, argv, scenemanager);
    return 0;
}