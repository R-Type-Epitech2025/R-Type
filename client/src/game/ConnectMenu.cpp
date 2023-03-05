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
        //_connectMenu->addEntity(InitIdText());
        _connectMenu->addEntity(InitOptionButton());
        _connectMenu->addEntity(InitText(50, 100, "Enter Ip and Port as : \"ip:port", 70, false, 21));
        _connectMenu->addEntity(InitText(150, 270, "127.0.0.1:4242", 70, true, 20));
        _connectMenu->addEntity(InitPlayButton());
    }

    ConnectMenu::~ConnectMenu() {
    }
    
    Entity *ConnectMenu::InitText(int x, int y, std::string inputText, u_int32_t textSize, bool isWritable, u_int32_t id) {
        sf::Color textColor = sf::Color::White;

        Entity *text = new Entity(EntityType::TEXT, {x, y}, textSize, textColor, id, true, inputText, isWritable);
        return text;
    }

    Entity *ConnectMenu::InitPlayButton() {
        Entity *button = new Entity(EntityType::BUTTON , {200, 600},{0, 0}, {570, 279}, 1.0, "./assets/Buttons/PlayButton.png", 4, true);
        return button;
    }

    Entity *ConnectMenu::InitBackground() {
        Entity *background = new Entity(EntityType::BACKGROUND, {0, 0}, {0, 0}, {1920, 1080}, 1.0, "assets/background.png", 1, true);
        return background;
    }

    Entity *ConnectMenu::InitOptionButton() {
        Entity *optionButton = new Entity(EntityType::BUTTON, {125, 200}, {0, 0}, {727, 279}, 1.0, "assets/Buttons/EmptyButton.png", 2, true);
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
