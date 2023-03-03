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
        GraphicComponent::GraphicComponent(std::string sprite, std::vector<int> positioninsprite_sheet,std::vector<int> sizespritesheet, std::vector<int> sizeScreen, std::vector<int> positioninscreen) {
            isPrintable = true;
            createSprite(sprite, positioninsprite_sheet.at(0), positioninsprite_sheet.at(1), sizespritesheet.at(0), sizespritesheet.at(1), 1);
            setPosition(positioninscreen.at(0), positioninscreen.at(1));
            setSize(sizeScreen.at(0), sizeScreen.at(1));
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
        
        void GraphicComponent::setSize(float scale) {
            sprite.setScale(scale, scale);
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
