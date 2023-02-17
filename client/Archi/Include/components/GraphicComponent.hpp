/*
** EPITECH PROJECT, 2023
** Archi
** File description:
** GraphicComponent
*/

#ifndef GRAPHICCOMPONENT_HPP_
#define GRAPHICCOMPONENT_HPP_
#include <SFML/Graphics.hpp>


namespace rtype{
    class GraphicComponent {
        public:
            GraphicComponent();
            ~GraphicComponent();
            void createSprite(const std::string &imagePath, int spriteWidth, int spriteHeight);
            void setPosition(int x, int y);
            void setSpritePosition(int x, int y);
            void setSize(int width, int height);
            bool getIsPrintable();
            sf::Sprite* getSprite();
            void setRotation(float angle);
            void setHitbox(sf::IntRect rect);

            struct Position {
                int x;
                int y;
                int sprite_x;
                int sprite_y;
            };
        
            Position position;
        
            struct Size {
                int width;
                int height;
            };
        
            Size size;
        protected:
        private:
            sf::Texture texture;
            sf::Sprite* sprite;
            bool isPrintable;
            float angle;
            sf::IntRect rect;
    };
}

#endif /* !GRAPHICCOMPONENT_HPP_ */
