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
            void addScene(std::string scene_name, rtype::Scene *scene);
            rtype::Scene* getCurrentScene();

        protected:
            std::map<std::string, rtype::Scene*> _scenes;
            rtype::Scene* _currentscene;
            bool _shouldClose;

        private:
    };
};

#endif /* !SCENEMANAGER_HPP_ */
