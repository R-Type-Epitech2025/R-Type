/*
** EPITECH PROJECT, 2023
** Archi
** File description:
** SceneManager
*/

#include "SceneManager.hpp"

rtype::SceneManager::SceneManager()
{
}

rtype::SceneManager::~SceneManager()
{
}

void rtype::SceneManager::setScene(std::string scene)
{
    this->_currentscene = this->_scenes[scene];
}

void rtype::SceneManager::addScene(std::string scene_name, rtype::Scene *scene){
    this->_scenes[scene_name] = scene;
}

// const std::string &getScene()
// {
//     return (this->scene);
// }
