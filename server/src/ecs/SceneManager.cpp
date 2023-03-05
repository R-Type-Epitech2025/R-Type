/*
** EPITECH PROJECT, 2023
** Archi
** File description:
** SceneManager
*/

#include "SceneManager.hpp"
#include "Entity.hpp"
#include <iostream>

namespace rtype {
    SceneManager::SceneManager()
    {
    }

    SceneManager::~SceneManager()
    {
    }

    void SceneManager::setScene(std::string scene)
    {
        std::cout << this->_scenes.size() << std::endl;
        this->_currentscene = this->_scenes[scene];
    }

    void SceneManager::addScene(std::string scene_name, Scene *scene){
        this->_scenes[scene_name] = scene;
    }

    Scene* SceneManager::getCurrentScene(){
        return (this->_currentscene);
    }
}