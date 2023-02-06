/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** SceneManager
*/

#ifndef SCENEMANAGER_HPP
#define SCENEMANAGER_HPP

#include <iostream>
#include <vector>
#include "IScene.hpp"

namespace rtype 
{
    class SceneManager 
    {
    public:

        /**
         * @brief Enum of all the scene
         * 
         */
        enum class SceneType {
            NONE = -1,
            GAME,
            MAIN_MENU,
            HELP,
            PAUSE,
            OPTION,
            END
        };

        /**
         * @brief Construct a new Scene Manager object
         * 
         * @param scene 
         */
        void addScene(IScene *scene);

        /**
         * @brief Destroy the Scene Manager object
         * 
         */
        void removeScene(int Index);

        /**
         * @brief Set the Active Scene object
         * 
         * @param Index 
         */
        void setActiveScene(int Index);

        /**
         * @brief Update the scene
         * 
         */
        void update();

        /**
         * @brief Draw the scene
         * 
         */
        void draw();

    private:
        std::vector<IScene*> scenes;
        int activeScene;
    };
}

#endif /* !SCENEMANAGER_HPP */
