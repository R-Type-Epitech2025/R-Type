/*
** EPITECH PROJECT, 2023
** client
** File description:
** OptionMenu
*/

#include "OptionMenu.hpp"

namespace rtype {

    Entity *OptionMenu::InitPlayButton() {
        Entity *playButton = new Entity(EntityType::BUTTON, {300, 600}, {0, 0}, {300, 300}, 1.0, "assets/button_play.png", "play");
        return playButton;
    }

    Entity *OptionMenu::InitRestartButton() {
        Entity *restartButton = new Entity(EntityType::BUTTON, {900, 600}, {0, 0}, {300, 300}, 1.0, "assets/button_restart.png", "restart");
        return restartButton;
    }
    Entity *OptionMenu::InitExitButton() {
        Entity *exitButton = new Entity(EntityType::BUTTON, {100, 900}, {0, 0}, {100, 100}, 1.0, "assets/button_close.png", "close");
        return exitButton;
    }

    Entity *OptionMenu::InitOptionButton() {
        Entity *optionButton = new Entity(EntityType::BUTTON, {600, 600}, {0, 0}, {300, 300}, 1.0, "assets/button_settings.png", "settings");
        return optionButton;
    }

    Entity *OptionMenu::InitBackground() {
        Entity *background = new Entity(EntityType::BACKGROUND, {0, 0}, {0, 0}, {1920, 1080}, 2.0, "assets/background.png", "background");
        return background;
    }

    Scene *OptionMenu::OPTION_MENU() {
        Scene *optionMenu = new Scene();
        optionMenu->addEntity(InitPlayButton());
        optionMenu->addEntity(InitExitButton());
        optionMenu->addEntity(InitOptionButton());
        optionMenu->addEntity(InitRestartButton());
        optionMenu->addEntity(InitBackground());
        return optionMenu;
    }
};