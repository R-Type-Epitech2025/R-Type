/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** game
*/
#ifdef GAME_HPP
#define GAME_HPP

#include <map>
#include <iostream>

#include "systems/ISystem.hpp"
#include "SceneManager.hpp"

namespace rType
{
    class Game
    {
    public:
        Game();
        ~Game();

        void mainLoop();
        

    private:
        SceneManager _sceneManager;
        bool _end = false;
    };
}