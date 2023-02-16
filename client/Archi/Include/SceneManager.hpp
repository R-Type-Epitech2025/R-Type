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
        /**
         * @brief Construct a new Scene Manager object
         * 
         */
        SceneManager();

        /**
         * @brief Destroy the Scene Manager object
         * 
         */
        ~SceneManager();

        /**
         * @brief 
         * 
         * @param scene 
         */
        const std::string &getScene() const;

        /**
         * @brief 
         * 
         * @param scene 
         */
        void setScene(std::string scene);

    protected:
        std::map<std::string, std::string> _scenes;
        SceneType _currentScene;
        bool _shouldClose;

    private:
};
};

#endif /* !SCENEMANAGER_HPP_ */
