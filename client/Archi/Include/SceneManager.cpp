/*
** EPITECH PROJECT, 2023
** Archi
** File description:
** SceneManager
*/

#include "SceneManager.hpp"
#include "Entity.hpp"

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

rtype::Scene* rtype::SceneManager::getCurrentScene(){
    // sort(_currentscene->get_entity().begin(), _currentscene->get_entity().end(), [] (rtype::Entity *x, rtype::Entity *y) { return x->_type < y->_type; });
    return (this->_currentscene);
}

// const std::string &getScene()
// {
//     return (this->scene);
// }
