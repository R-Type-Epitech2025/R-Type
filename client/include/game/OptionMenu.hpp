/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** OptionMenu
*/

#ifndef OPTIONMENU_HPP_
#define OPTIONMENU_HPP_

#include "SceneManager.hpp"
#include "Entity.hpp"

namespace rtype {
class OptionMenu {
    public:
        OptionMenu();
        ~OptionMenu();
        Scene *OPTION_MENU();

    protected:
    private:
        Entity *InitPlayButton();
        Entity *InitRestartButton();
        Entity *InitExitButton();
        Entity *InitOptionButton();
        Entity *InitBackground();
};
};

#endif /* !OPTIONMENU_HPP_ */
