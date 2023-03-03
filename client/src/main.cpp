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
    rtype::Core core;
    core.run(argc, argv);
    return 0;
}