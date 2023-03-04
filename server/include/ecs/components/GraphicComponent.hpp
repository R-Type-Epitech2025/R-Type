/*
** EPITECH PROJECT, 2023
** Archi
** File description:
** GraphicComponent
*/

#ifndef GRAPHICCOMPONENT_HPP_
#define GRAPHICCOMPONENT_HPP_
#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>

namespace rtype{
    class GraphicComponent {
        public:
            GraphicComponent(std::string sprite, std::vector<int> positioninsprite_sheet, std::vector<int> sizespritesheet, float scale, std::vector<int> positioninscreen);
            ~GraphicComponent();
            void createSprite(const std::string &imagePath, int spritePosX, int spritePosY,int spriteWidth, int spriteHeight, int nb_sprite);
            void setPosition(int x, int y);
            void setSpritePosition(int x, int y);
            void setSize(float scale);
            bool getIsPrintable();
            sf::Sprite getSprite();
            void setRotation(float angle);
            void setHitbox(sf::IntRect rect);

            struct SpritePosition {
                int x;
                int y;
                int sprite_x;
                int sprite_y;
            };
        
            SpritePosition position;
        
            struct SpriteSize {
                int width;
                int height;
            };
        
            SpriteSize size;
            int nb_sprites;
            int counter_sprites;
            int initial_sprite_x;

        protected:
        private:
            sf::Texture texture;
            sf::Sprite sprite;
            bool isPrintable;
            float angle;
            sf::IntRect rect;
    };
}

#endif /* !GRAPHICCOMPONENT_HPP_ */
