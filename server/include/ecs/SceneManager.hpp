/*
** EPITECH PROJECT, 2023
** sceneManager
** File description:
** SceneManager
*/

#ifndef SCENEMANAGER_HPP_
#define SCENEMANAGER_HPP_

#include "Scene.hpp"
#include <map>

namespace rtype {
    enum SceneType{
        NONE,
        MAIN_MENU,
        HELP,
        ENDGAME,
        DEATH,
        PAUSE
    };
    class SceneManager {
        public:
            /**
             ** @brief Construct a new Scene Manager object
             ** 
             */
            SceneManager();

            /**
             ** @brief Destroy the Scene Manager object
             ** 
             */
            ~SceneManager();

            /**
             ** @brief get scene
             ** 
             ** @param scene 
             */
            const std::string &getScene() const;

            /**
             ** @brief 
             ** 
             ** @param scene 
             */
            void setScene(std::string scene);

            /**
             ** @brief add scene
             ** 
             ** @param scene_name 
             ** @param scene 
             */
            void addScene(std::string scene_name, Scene *scene);

            /**
             ** @brief Get the Current Scene object
             ** 
             ** @return Scene* 
             */
            Scene* getCurrentScene();
        protected:
            std::map<std::string, Scene*> _scenes;
            Scene* _currentscene;
            bool _shouldClose;
        private:
    };
};

#endif /* !SCENEMANAGER_HPP_ */
