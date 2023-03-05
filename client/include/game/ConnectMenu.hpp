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

        Scene *_connectMenu;
    protected:
        Entity *InitText(int x, int y, std::string inputText, quint32 textSize, bool isWritable, quint32 id);
        Entity *InitBackground();
        Entity *InitOptionButton();
        Entity *InitExitButton();
        Entity *InitIdText();
        Entity *InitPortText();
        Entity *InitPlayButton();
    private:
};
};

#endif /* !CONNECTMENU_HPP_ */
