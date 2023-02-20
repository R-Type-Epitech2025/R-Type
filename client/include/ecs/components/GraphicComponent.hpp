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

    enum Sprite_Direction {
        LEFT,
        RIGHT
    };
    class GraphicComponent {
        public:
            GraphicComponent();
            ~GraphicComponent();
            void createSprite(const std::string &imagePath, int spriteWidth, int spriteHeight, int nb_sprite, rtype::Sprite_Direction direction);
            void setPosition(int x, int y);
            void setSpritePosition(int x, int y, bool init = false);
            void setSize(int width, int height);
            bool getIsPrintable();
            sf::Sprite getSprite();
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
            int nb_sprites;
            int counter_sprites;
            int initial_sprite_x;
            rtype::Sprite_Direction _direction;

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
