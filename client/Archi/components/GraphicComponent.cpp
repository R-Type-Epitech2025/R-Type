/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** GraphicComponent
*/

#include "../Include/components/GraphicComponent.hpp"
#include <SFML/Graphics.hpp>

namespace rtype {
        GraphicComponent::GraphicComponent() {
            isPrintable = true;
        }
        
        GraphicComponent::~GraphicComponent() {
            delete sprite;
        }
        
        void GraphicComponent::createSprite(const std::string& imagePath, int spriteWidth, int spriteHeight) {
            texture.loadFromFile(imagePath);
            sprite = new sf::Sprite(texture, sf::IntRect(0, 0, spriteWidth, spriteHeight));
        }
        
        void GraphicComponent::setPosition(int x, int y) {
            position.x = x;
            position.y = y;
            sprite->setPosition(x, y);
        }
        
        void GraphicComponent::setSpritePosition(int x, int y) {
            position.sprite_x = x;
            position.sprite_y = y;
            sprite->setTextureRect(sf::IntRect(x, y, size.width, size.height));
        }
        
        void GraphicComponent::setSize(int width, int height) {
            size.width = width;
            size.height = height;
            sprite->setScale((float)width / sprite->getTextureRect().width, (float)height / sprite->getTextureRect().height);
        }
        
        bool GraphicComponent::getIsPrintable() {
            return isPrintable;
        }
        
        
        sf::Sprite* GraphicComponent::getSprite() {
            return sprite;
        }
};
