/*
** EPITECH PROJECT, 2023
** Archi
** File description:
** SceneManager
*/

#ifndef SCENEMANAGER_HPP_
#define SCENEMANAGER_HPP_
#include "IScene.hpp"


namespace rtype{
    class SceneManager {
        public:
            SceneManager();
            ~SceneManager();

        protected:
        private:
            bool _shouldClose;
            Scenetype _currentScene;
    };
}

#endif /* !SCENEMANAGER_HPP_ */
