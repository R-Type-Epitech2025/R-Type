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
            void createSprite(const std::string &imagePath, int spriteWidth, int spriteHeight, int nb_sprite);
            void setPosition(int x, int y);
            void setSpritePosition(int x, int y, bool init = false);
            void setSize(int width, int height);
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

            void Text(std::string fontpath, std::string str, int Size, sf::Color color);
            void drawText(sf::RenderWindow &window, int x, int y);



        protected:
        private:
            sf::Texture texture;
            sf::Sprite sprite;
            sf::Text text;
            sf::Font font;
            bool isPrintable;
            float angle;
            sf::IntRect rect;
    };
}

#endif /* !GRAPHICCOMPONENT_HPP_ */
