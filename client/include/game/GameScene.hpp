/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** GameScene
*/

#ifndef GAMESCENE_HPP_
#define GAMESCENE_HPP_

#include "SceneManager.hpp"
#include "Entity.hpp"

namespace rtype {
    class GameScene : public Scene {
        public:
            /**
             ** @brief Construct a new Game Scene object
             ** 
             **/
            GameScene();

            /**
             ** @brief Destroy the Game Scene object
             ** 
             **/
            ~GameScene();
    
            Scene *_gameScene;
        protected:
        private:
            Entity *InitBackground();
            Entity *InitBackground2();
            Entity *InitPlayer();
    };
};

#endif /* !GAMESCENE_HPP_ */
