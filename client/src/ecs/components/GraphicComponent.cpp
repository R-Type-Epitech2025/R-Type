/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** GraphicComponent
*/

#include "ecs/components/GraphicComponent.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
namespace rtype {
        GraphicComponent::GraphicComponent() {
            isPrintable = true;
        }
        
        GraphicComponent::~GraphicComponent() {
        
        }
        
        void GraphicComponent::createSprite(const std::string& imagePath, int spritePosX, int spritePosY, int spriteWidth, int spriteHeight, int nb_sprite) {
            size.height = spriteHeight;
            size.width = spriteWidth;
            position.sprite_x = spritePosX;
            position.sprite_y = spritePosY;
            nb_sprites = nb_sprite;
            texture.loadFromFile(imagePath);
            sprite = sf::Sprite(texture, sf::IntRect(spritePosX, spritePosY, spriteWidth, spriteHeight));
        }
        
        void GraphicComponent::setPosition(int x, int y) {
            position.x = x;
            position.y = y;
            sprite.setPosition(x, y);
        }
        
        void GraphicComponent::setSpritePosition(int x, int y, bool init) {
            if (init)
                initial_sprite_x = x;
            position.sprite_x = x;
            position.sprite_y = y;
            sprite.setTextureRect(sf::IntRect(x, y, size.width, size.height));
        }
        
        void GraphicComponent::setSize(int width, int height) {
            sprite.setScale((float)width / sprite.getTextureRect().width, (float)height / sprite.getTextureRect().height);
        }
        
        bool GraphicComponent::getIsPrintable() {
            return isPrintable;
        }
        
        
        sf::Sprite GraphicComponent::getSprite() {
            return sprite;
        }

        void GraphicComponent::setRotation(float angle) {
            this->angle = angle;
            sprite.setRotation(angle);
        }

        void GraphicComponent::setHitbox(sf::IntRect rect) {
            this->rect = rect;
            sprite.setTextureRect(rect);
        };
};
