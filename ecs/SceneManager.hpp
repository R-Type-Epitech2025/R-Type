/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** SceneManager
*/

#ifndef SCENEMANAGER_HPP
#define SCENEMANAGER_HPP

#include <iostream>

#include "IScene.hpp"

namespace rtype 
{
    class SceneManager 
    {
    public:
        enum class SceneType {
            NONE = -1,
            GAME,
            MAIN_MENU,
            HELP,
            PAUSE,
            OPTION,
            END
        };

        void addScene(std::unique_ptr<IScene> scene, SceneType sceneType);

        IScene &getCurrentScene();

        void setCurrentScene(SceneType scene, bool initScene = false);

        std::map<SceneType, std::unique_ptr<IScene>> &getScenes();

        
        // void setAddEntityCallback(std::function<void(std::shared_ptr<IEntity>)> callback);
        void setShouldClose(bool shouldClose);
        bool getShouldClose();
        // void setRemoveEntityCallback(std::function<void(std::shared_ptr<IEntity>)> callback);

        static SceneType &getCurrentSceneType();
        static SceneType &getPreviousSceneType();
        std::vector<SceneType> getSceneTypeList();
        IScene &getScene(SceneType sceneType);

    private:
        std::map<SceneType, std::unique_ptr<IScene>> _scenes;
        SceneType _currentScene = SceneType::NONE;
        bool _shouldClose = false;
    };
}

#endif /* !SCENEMANAGER_HPP */
