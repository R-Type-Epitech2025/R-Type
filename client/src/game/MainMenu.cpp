/*
** EPITECH PROJECT, 2023
** client
** File description:
** MainMenu
*/

#include "game.hpp"

namespace rtype {

    Entity *InitPlayButton() {
        Entity *playButton = new Entity(rtype::EntityType::BUTTON, {300, 600}, {0, 0}, {300, 300}, {0, 0}, "assets/button_play.png");
        return playButton;
    }

    Entity *InitExitButton() {
        Entity *exitButton = new Entity(rtype::EntityType::BUTTON, {100, 900}, {0, 0}, {100, 100}, {0, 0}, "assets/button_close.png");
        return exitButton;
    }

    Entity *InitOptionButton() {
        Entity *optionButton = new Entity(rtype::EntityType::BUTTON, {600, 600}, {0, 0}, {300, 300}, {0, 0}, "assets/button_settings.png");
        return optionButton;
    }

    Entity *InitBackground() {
        Entity *background = new Entity(rtype::EntityType::BACKGROUND, {0, 0}, {0, 0}, {1920, 1080}, {1920, 1080}, "assets/background.png");
        return background;
    }

    Scene *MAIN_MENU() {
        Scene *mainMenu = new Scene();
        mainMenu->addEntity(InitPlayButton());
        mainMenu->addEntity(InitExitButton());
        mainMenu->addEntity(InitOptionButton());
        mainMenu->addEntity(InitBackground());
        return mainMenu;
    }
};