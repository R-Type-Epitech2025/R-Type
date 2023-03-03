/*
** EPITECH PROJECT, 2023
** Archi
** File description:
** SceneManager
*/

#include "ecs/SceneManager.hpp"
#include "ecs/Entity.hpp"
#include <iostream>

rtype::SceneManager::SceneManager() : window(sf::VideoMode(0, 0), "R-Type")
{
}

rtype::SceneManager::~SceneManager()
{
}

void rtype::SceneManager::setScene(std::string scene)
{
    std::cout << this->_scenes.size() << std::endl;
    this->_currentscene = this->_scenes[scene];
}

void rtype::SceneManager::addScene(std::string scene_name, rtype::Scene *scene){
    this->_scenes[scene_name] = scene;
}

rtype::Scene* rtype::SceneManager::getCurrentScene(){
    // sort(_currentscene->get_entity().begin(), _currentscene->get_entity().end(), [] (rtype::Entity *x, rtype::Entity *y) { return x->_type < y->_type; });
    return (this->_currentscene);
}

// const std::string &getScene()
// {
//     return (this->scene);
// }
