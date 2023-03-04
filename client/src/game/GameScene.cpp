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
}

GameScene::~GameScene()
{
}

    Entity *GameScene::InitBackground() {
        Entity *background = new Entity(EntityType::BACKGROUND ,{0, 0},{0 , 0}, {1920, 1080}, 2.0, "./assets/backgournd2.jpg", 1);
        return background;
    }
    Entity *GameScene::InitPlayer() {
        Entity *spaceShip = new Entity(EntityType::MAIN_PLAYER , {500, 500},{0, 0}, {500, 500}, 1.0, "./assets/r-typesheet42.gif", 2);
        return spaceShip;
    }
    Entity *GameScene::InitEnemy() {
        int mobType = std::rand()%8 * 32;
        Entity *ennemy = new Entity(EntityType::MOB, {1000, std::rand()%1064}, {mobType, 0}, {32, 32}, 3.0, "./assets/sprites.png", 3);
        return ennemy;
    }
    Entity *GameScene::InitPlayButton() {
        Entity *button = new Entity(EntityType::BUTTON , {500, 500},{0, 0}, {500, 500}, 1.0, "./assets/button_play.png", 4);
        return button;
    }

    Scene *GameScene::creategameScene() {
        Scene *scene = new Scene("gameScene");
        scene->addEntity(InitBackground());
        scene->addEntity(InitPlayButton());
        scene->addEntity(InitPlayer());
        scene->addEntity(InitEnemy());
        return scene;
    }
};