/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** MainMenu
*/

#ifndef MAINMENU_HPP_
#define MAINMENU_HPP_

#include "SceneManager.hpp"
#include "Entity.hpp"

namespace rtype {
    class MainMenu {
        public:
            MainMenu();
            ~MainMenu();
            Scene *_mainMenu;
        protected:
        private:
            Entity *InitPlayButton();
            Entity *InitLogo();
            Entity *InitBackground();
    };
};

#endif /* !MAINMENU_HPP_ */
