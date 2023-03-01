/*
** EPITECH PROJECT, 2023
** client
** File description:
** MainMenu
*/

#include "MainMenu.hpp"

namespace rtype {
    MainMenu::MainMenu()
    {
    }

    MainMenu::~MainMenu()
    {
    }

    int MainMenu::loadFont()
    {
        if (!font.loadFromFile("assets/fonts/arial.ttf"))
            return 84;
        return 0;
    }

    void MainMenu::createTextButton()
    {
        sf::Text titleText("Main Menu", font, 50);
        titleText.setColor(sf::Color::Red);
        titleText.setPosition(300, 50);

        sf::Text playText("Play", font, 30);
        playText.setColor(sf::Color::Red);
        playText.setPosition(350, 200);

        sf::Text optionsText("Options", font, 30);
        optionsText.setColor(sf::Color::Red);
        optionsText.setPosition(350, 250);

        sf::Text exitText("Exit", font, 30);
        exitText.setColor(sf::Color::Red);
        exitText.setPosition(350, 300);

        if(event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // Check which text was clicked
                    if (playText.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        //call event system
                    }
                    else if (optionsText.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        //call event system
                    }
                    else if (exitText.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        //call event system
                }
    }
};