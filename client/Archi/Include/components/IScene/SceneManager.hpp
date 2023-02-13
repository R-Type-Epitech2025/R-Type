/*
** EPITECH PROJECT, 2023
** sceneManager
** File description:
** SceneManager
*/

#ifndef SCENEMANAGER_HPP_
#define SCENEMANAGER_HPP_

#include <iostream>
#include <map>
#include "IScene.hpp"


namespace rtype {
class SceneManager {
    public:
        SceneManager();
        ~SceneManager();

    protected:
        std::map<std::string, std::string> _scenes;
        SceneType _currentScene;
        bool _shouldClose;

    private:
};
};

#endif /* !SCENEMANAGER_HPP_ */
