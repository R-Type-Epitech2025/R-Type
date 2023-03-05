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
        //destroy all entities in scene aller vasy encule
    }

    Entity *GameScene::InitBackground() {
        Entity *background = new Entity(EntityType::BACKGROUND ,{0, 0},{0 , 0}, {1920, 1080}, 1.0, "./assets/background2.png", 1, true, {-15, 0});
        background->container.movement_component->isParallax = true;
        return background;
    }

    Entity *GameScene::InitBackground2() {
        Entity *background = new Entity(EntityType::BACKGROUND ,{1920, 0},{0 , 0}, {1920, 1080}, 1.0, "./assets/background2.png", 2, true, {-15, 0});
        background->container.movement_component->isParallax = true;
        return background;
    }

    Entity *GameScene::InitPlayer() {
        Entity *spaceShip = new Entity(EntityType::MAIN_PLAYER , {500, 500},{0, 0}, {500, 500}, 1.0, "./assets/r-typesheet42.gif", 3, true);
        return spaceShip;
    }
}