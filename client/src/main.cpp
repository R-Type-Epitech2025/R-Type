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
    sf::RenderWindow window(sf::VideoMode(800, 600), "My Game");
    window.setFramerateLimit(60);
    window.clear(sf::Color::Black);
    rtype::Core core;
    core.run(argc, argv, window);
    return 0;
}