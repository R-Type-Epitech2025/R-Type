/*
** EPITECH PROJECT, 2023
** client
** File description:
** OptionMenu
*/

#include "SceneManager.hpp"

namespace rtype {

    Entity *InitPlayButton() {
        Entity *playButton = new Entity(rtype::EntityType::BUTTON, {300, 600}, {0, 0}, {300, 300}, {0, 0}, "assets/button_play.png");
        return playButton;
    }

    Entity *InitRestartButton() {
        Entity *restartButton = new Entity(rtype::EntityType::BUTTON, {900, 600}, {0, 0}, {300, 300}, {0, 0}, "assets/button_restart.png");
        return restartButton;
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

    Scene *OPTION_MENU() {
        Scene *optionMenu = new Scene();
        optionMenu->addEntity(InitPlayButton());
        optionMenu->addEntity(InitExitButton());
        optionMenu->addEntity(InitOptionButton());
        optionMenu->addEntity(InitRestartButton());
        optionMenu->addEntity(InitBackground());
        return optionMenu;
    }
};