/*
** EPITECH PROJECT, 2023
** client
** File description:
** GameSystem
*/

#include "GameSystem.hpp"

namespace rtype{
    GameSystem::GameSystem(QObject *parent) : QObject(parent)
    {
    }

    GameSystem::~GameSystem()
    {
    }

    void GameSystem::onNewPlayerConnected(quint32 id)
    {
        std::cout << "New player connected with id: " << id << std::endl;
    }

    void GameSystem::onPlayerDisconnected(quint32 id)
    {
        std::cout << "Player disconnected with id: " << id << std::endl;
    }

    void GameSystem::onPlayerShoot(quint32 id)
    {
        std::cout << "Player " << id << " shoot" << std::endl;
    }

    
    void GameSystem::parralax(std::string imagePath, std::string imageForeground, float speed, float x, float y, float width) {

        std::cout << "parralax" << std::endl;
        sf::Texture backgroundTexture;
        backgroundTexture.loadFromFile(imagePath);
        sf::Sprite background(backgroundTexture);
        sf::Texture foregroundTexture;  
        foregroundTexture.loadFromFile();
        sf::Sprite foreground(foregroundTexture);
        background.setPosition(0, 0);
        background.setScale(2.0f, 2.0f);
        background.setOrigin(background.getLocalBounds().width / 2, background.getLocalBounds().height / 2);
        float backgroundSpeed = 0.1f;
        foreground.setPosition(0, 0);
        foreground.setScale(2.0f, 2.0f);
        foreground.setOrigin(foreground.getLocalBounds().width / 2, foreground.getLocalBounds().height / 2);
        float foregroundSpeed = 0.5f;
    }
}