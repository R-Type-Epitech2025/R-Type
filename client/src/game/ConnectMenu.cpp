/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** ConnectMenu
*/

#include "ConnectMenu.hpp"

namespace rtype {
    Entity *ConnectMenu::InitBackground() {
        Entity *background = new Entity(EntityType::BACKGROUND, {0, 0}, {0, 0}, {1920, 1080}, 2.0, "assets/background.png", "background");
        return background;
    }

    Entity *ConnectMenu::InitOptionButton() {
        Entity *optionButton = new Entity(EntityType::BUTTON, {600, 600}, {0, 0}, {300, 300}, 1.0, "assets/button_settings.png", "settings");
        return optionButton;
    }

    Entity *ConnectMenu::InitExitButton() {
        Entity *exitButton = new Entity(EntityType::BUTTON, {100, 900}, {0, 0}, {100, 100}, 1.0, "assets/button_close.png", "close");
        return exitButton;
    }

    Entity *ConnectMenu::InitIdText() {
        Entity *idText = new Entity(EntityType::TEXT, {100, 300}, {0, 0}, {100, 100}, 1.0, "assets/button_left.png", "id");
        return idText;
    }

    Entity *ConnectMenu::InitPortText() {
        Entity *idText = new Entity(EntityType::TEXT, {100, 500}, {0, 0}, {100, 100}, 1.0, "assets/button_left.png", "port");
        return idText;
    }

    Scene *ConnectMenu::CONNECT_MENU() {
        Scene *connectMenu = new Scene();
        connectMenu->addEntity(InitBackground());
        connectMenu->addEntity(InitOptionButton());
        connectMenu->addEntity(InitExitButton());
        connectMenu->addEntity(InitIdText());
        connectMenu->addEntity(InitPortText());
        return connectMenu;
    }
};
