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
class GameScene {
    public:
        GameScene();
        ~GameScene();
        Scene *creategameScene();

    protected:
    private:
        Entity *InitBackground();
        Entity *InitPlayer();
        Entity *InitEnemy();
        Entity *InitPlayButton();

};
};

#endif /* !GAMESCENE_HPP_ */
