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

#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif
#include<iostream>

std::string get_current_dir() {
   char buff[FILENAME_MAX]; //create string buffer to hold path
   GetCurrentDir( buff, FILENAME_MAX );
   std::string current_working_dir(buff);
   return current_working_dir;
}


int main(int argc, char* argv[]) {
    std::cout << get_current_dir() << std::endl;
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "My Game");
    window.setFramerateLimit(60);
    window.clear(sf::Color::Black);
    rtype::Core core;
    rtype::SceneManager *scenemanager = new rtype::SceneManager();
    core.run(argc, argv, scenemanager);
    return 0;
}