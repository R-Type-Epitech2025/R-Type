/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** GameSystem
*/

#include "GameSystem.hpp"

namespace rtype {

GameSystem::GameSystem() : _sceneManager(new SceneManager()), _systemManager(new SystemManager())
{
}

GameSystem::~GameSystem()
{
}

void GameSystem::LoadScene()
{
    Scene *menu = MainMenu.create();
    Scene *gameScene = creategameScene();
    _sceneManager->addScene(gameScene);
    _sceneManager->addScene(menu)
}
};
