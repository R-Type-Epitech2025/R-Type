/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** GameSystem
*/

#ifndef GAMESYSTEM_HPP_
#define GAMESYSTEM_HPP_

#include "SystemManager.hpp"
#include "ConnectMenu.hpp"
#include "GameScene.hpp"
#include "OptionMenu.hpp"
#include "MainMenu.hpp"

namespace rtype {
class GameSystem {
    public:
        GameSystem();
        ~GameSystem();
        void LoadScene();
    protected:
    private:
        SceneManager *_sceneManager;
        SystemManager *_systemManager;
};
};

#endif /* !GAMESYSTEM_HPP_ */
