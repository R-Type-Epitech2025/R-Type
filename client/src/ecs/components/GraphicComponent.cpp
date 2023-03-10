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
    GraphicComponent::GraphicComponent(std::string sprite, std::vector<int> positioninsprite_sheet,std::vector<int> sizespritesheet, float scale, std::vector<int> positioninscreen, bool isPrint) {
        _print = isPrint;
        createSprite(sprite, positioninsprite_sheet.at(0), positioninsprite_sheet.at(1), sizespritesheet.at(0), sizespritesheet.at(1), 1);
        setPosition(positioninscreen.at(0), positioninscreen.at(1));
        setSize(scale);
    }
        
        GraphicComponent::GraphicComponent(std::vector<int> positioninscreen, u_int32_t fontSize, sf::Color& textColor, bool isPrint) {
            _print = isPrint;

            if (!_font.loadFromFile("assets/Texts/arial-unicode-ms.ttf")) {
                std::cout << "Error loading font" << std::endl;
                exit(84);
            }
            _inputText = "";
            _text = sf::Text(_inputText, _font, fontSize);
            setPosition(positioninscreen.at(0), positioninscreen.at(1));
        }

        GraphicComponent::GraphicComponent(EntityCreator_t *entityCreator, sf::Texture *textureFrom) {
            _print = true;
            createSprite(entityCreator->spriteName, entityCreator->posSheet.at(0), entityCreator->posSheet.at(1), entityCreator->sizeSheet.at(0), entityCreator->sizeSheet.at(1), 1);
            setPosition(entityCreator->positionInScreen.at(0), entityCreator->positionInScreen.at(1));
            setSize(entityCreator->scale);
            texture = *textureFrom;
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
            return _print;
        }
        
        sf::Text GraphicComponent::getText() {
            return _text;
        }
        
        std::string GraphicComponent::getInputText() {
            return _inputText;
        }

        void GraphicComponent::setInputText(std::string inputText) {
            _inputText = inputText;
            _text.setString(_inputText);
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

        int GraphicComponent::setfont(std::string fonts) {
            if (!_font.loadFromFile(fonts))
            {
                std::cerr << "Impossible de charger la police de caract??res !" << std::endl;
                return EXIT_FAILURE;
            }
            return EXIT_SUCCESS;
        }

        void GraphicComponent::update(EntityCreator_t *entity)
        {
            
        }
};