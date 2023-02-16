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

void setScene(std::map<std::string, std::string> scene)
{
    this->_scene = scene;
}

const std::map<std::string, std::string> &getScene()
{
    return (this->scene);
}
