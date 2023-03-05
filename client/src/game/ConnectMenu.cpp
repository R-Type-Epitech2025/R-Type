/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** ConnectMenu
*/

#include "ConnectMenu.hpp"

namespace rtype {
    ConnectMenu::ConnectMenu() {
        _connectMenu = new Scene("connectMenu");
        _connectMenu->addEntity(InitBackground());
        _connectMenu->addEntity(InitOptionButton());
        _connectMenu->addEntity(InitExitButton());
        _connectMenu->addEntity(InitIdText());
        _connectMenu->addEntity(InitPortText());
        _connectMenu->addEntity(InitText());
    }

    ConnectMenu::~ConnectMenu() {
    }
    
    Entity *ConnectMenu::InitText() {
        sf::Color textColor = sf::Color::White;

        Entity *text = new Entity(EntityType::TEXT, {50, 50}, 30, textColor, 3, true);
        return text;
    }

    Entity *ConnectMenu::InitBackground() {
        Entity *background = new Entity(EntityType::BACKGROUND, {0, 0}, {0, 0}, {1920, 1080}, 1.0, "assets/background.png", 1, true);
        return background;
    }

    Entity *ConnectMenu::InitOptionButton() {
        Entity *optionButton = new Entity(EntityType::BUTTON, {600, 600}, {0, 0}, {300, 300}, 1.0, "assets/button_settings.png", 2, true);
        return optionButton;
    }

    Entity *ConnectMenu::InitExitButton() {
        Entity *exitButton = new Entity(EntityType::BUTTON, {100, 900}, {0, 0}, {100, 100}, 1.0, "assets/button_close.png", 3, true);
        return exitButton;
    }

    Entity *ConnectMenu::InitIdText() {
        Entity *idText = new Entity(EntityType::TEXT, {100, 300}, {0, 0}, {100, 100}, 1.0, "assets/button_left.png", 12, true);
        return idText;
    }

    Entity *ConnectMenu::InitPortText() {
        Entity *idText = new Entity(EntityType::TEXT, {100, 500}, {0, 0}, {100, 100}, 1.0, "assets/button_left.png", 5, true);
        return idText;
    }
};
