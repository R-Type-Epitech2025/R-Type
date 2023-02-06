/*
** EPITECH PROJECT, 2023
** ecs
** File description:
** SceneManager
*/

#include "SceneManager.hpp"
#include <SFML/Graphics.hpp>

namespace rtype {
    SceneManager::SceneManager()
    {
    }

    SceneManager::~SceneManager()
    {
    }

    void SceneManager::addScene(IScene *scene)
    {
        scenes.push_back(scene);
    }

    void SceneManager::removeScene(int Index)
    {
        scenes.erase(scenes.begin() + Index);
    }

    void SceneManager::setActiveScene(int Index)
    {
        activeScene = Index;
    }

    void SceneManager::update()
    {
        scenes.at(activeScene)->update();
    }

    void SceneManager::draw()
    {
        scenes.at(activeScene)->draw();
    }
}
