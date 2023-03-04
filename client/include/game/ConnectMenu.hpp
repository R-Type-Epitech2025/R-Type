/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** ConnectMenu
*/

#ifndef CONNECTMENU_HPP_
#define CONNECTMENU_HPP_

#include "Scene.hpp"

namespace rtype {
class ConnectMenu {
    public:
        ConnectMenu();
        ~ConnectMenu();

        Scene *CONNECT_MENU();
    protected:
        Entity *InitBackground();
        Entity *InitOptionButton();
        Entity *InitExitButton();
        Entity *InitIdText();
        Entity *InitPortText();
    private:
};
};

#endif /* !CONNECTMENU_HPP_ */
