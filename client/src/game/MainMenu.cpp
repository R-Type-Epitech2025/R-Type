/*
** EPITECH PROJECT, 2023
** client
** File description:
** MainMenu
*/

#include "MainMenu.hpp"

namespace rtype {

    MainMenu::MainMenu() {
        _mainMenu = new Scene("mainMenu");
        _mainMenu->addEntity(InitBackground());
        _mainMenu->addEntity(InitPlayButton());
        _mainMenu->addEntity(InitLogo());
    }

    MainMenu::~MainMenu() {
    }

    Entity *MainMenu::InitPlayButton() {
        Entity *button = new Entity(EntityType::BUTTON , {675, 600},{0, 0}, {570, 279}, 1.0, "./assets/Buttons/PlayButton.png", 4, true);
        return button;
    }

    Entity *MainMenu::InitLogo() {
        Entity *logo = new Entity(EntityType::BUTTON, {360, 5}, {0, 0}, {1200, 665}, 1.0, "assets/superRtype.png", 2, true);
        return logo;
    }

    Entity *MainMenu::InitBackground() {
        Entity *background = new Entity(EntityType::BACKGROUND, {0, 0}, {0, 0}, {1920, 1080}, 1.0, "assets/background.png", 1, true);
        return background;
    }
};