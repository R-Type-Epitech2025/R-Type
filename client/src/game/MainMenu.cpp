/*
** EPITECH PROJECT, 2023
** client
** File description:
** MainMenu
*/

#include "MainMenu.hpp"

namespace rtype {

    Entity *MainMenu::InitPlayButton() {
        Entity *button = new Entity(EntityType::BUTTON , {500, 500},{0, 0}, {500, 500}, 1.0, "./assets/button_play.png", 4);
        return button;
    }

    Entity *MainMenu::InitExitButton() {
        Entity *exitButton = new Entity(EntityType::BUTTON, {100, 900}, {0, 0}, {100, 100}, 1.0, "assets/button_close.png", 3);
        return exitButton;
    }

    Entity *MainMenu::InitOptionButton() {
        Entity *optionButton = new Entity(EntityType::BUTTON, {600, 600}, {0, 0}, {300, 300}, 1.0, "assets/button_settings.png", 2);
        return optionButton;
    }

    Entity *MainMenu::InitBackground() {
        Entity *background = new Entity(EntityType::BACKGROUND, {0, 0}, {0, 0}, {1920, 1080}, 2.0, "assets/background.png", 1);
        return background;
    }

    Scene *MainMenu::Main_Menu() {
        Scene *mainMenu = new Scene("mainMenu");
        mainMenu->addEntity(InitBackground());
        mainMenu->addEntity(InitPlayButton());
        mainMenu->addEntity(InitExitButton());
        mainMenu->addEntity(InitOptionButton());
        return mainMenu;
    }
};