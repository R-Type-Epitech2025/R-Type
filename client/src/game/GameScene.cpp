/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** GameScene
*/

#include "GameScene.hpp"

namespace rtype {
    GameScene::GameScene()
    {
        _gameScene = new Scene("gameScene");
        _gameScene->addEntity(InitBackground());
        _gameScene->addEntity(InitBackground2());
        _gameScene->addEntity(InitPlayer());
    }

    GameScene::~GameScene()
    {
    }

    Entity *GameScene::InitBackground() {
        Entity *background = new Entity(EntityType::BACKGROUND ,{0, 0},{0 , 0}, {1920, 1080}, 1.0, "./assets/backgournd2.jpg", 1, true, {-5, 0});
        return background;
    }

    Entity *GameScene::InitBackground2() {
        Entity *background = new Entity(EntityType::BACKGROUND ,{1920, 0},{0 , 0}, {1920, 1080}, 1.0, "./assets/backgournd2.jpg", 1, true, {-5, 0});
        return background;
    }

    Entity *GameScene::InitPlayer() {
        Entity *spaceShip = new Entity(EntityType::MAIN_PLAYER , {500, 500},{0, 0}, {500, 500}, 1.0, "./assets/r-typesheet42.gif", 2, true);
        return spaceShip;
    }

}