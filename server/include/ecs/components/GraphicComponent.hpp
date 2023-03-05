/*
** EPITECH PROJECT, 2023
** Archi
** File description:
** GraphicComponent
*/

#ifndef GRAPHICCOMPONENT_HPP_
#define GRAPHICCOMPONENT_HPP_

#include <SFML/Graphics.hpp>
#include <QtNetwork>
#include <memory>
#include <iostream>

namespace rtype{
    class GraphicComponent {
        public:

            /**
             ** @brief Construct a new Graphic Component object
             ** 
             ** @param sprite 
             ** @param positioninsprite_sheet 
             ** @param sizespritesheet 
             ** @param scale 
             ** @param positioninscreen 
             */
            GraphicComponent(std::string sprite, std::vector<int> positioninsprite_sheet, std::vector<int> sizespritesheet, float scale, std::vector<int> positioninscreen);

            /**
             ** @brief Destroy the Graphic Component object
             ** 
             */
            ~GraphicComponent();

            /**
             ** @brief Create a Sprite object
             ** 
             ** @param imagePath 
             ** @param spritePosX 
             ** @param spritePosY 
             ** @param spriteWidth 
             ** @param spriteHeight 
             ** @param nb_sprite 
             */
            void createSprite(const std::string &imagePath, int spritePosX, int spritePosY,int spriteWidth, int spriteHeight, int nb_sprite);
            
            /**
             ** @brief Set the Position object
             ** 
             ** @param x 
             ** @param y 
             */
            void setPosition(int x, int y);

            /**
             ** @brief Set the Sprite Position object
             ** 
             ** @param x 
             ** @param y 
             ** @param init 
             */
            void setSpritePosition(quint32 x, quint32 y, bool init = false);

            /**
             ** @brief Set the Size object
             ** 
             ** @param scale 
             */
            void setScale(float scale);

            /**
             ** @brief Get the Is Printable object
             ** 
             ** @return true 
             ** @return false 
             */
            bool getIsPrintable();

            /**
             ** @brief Get the Sprite object
             ** 
             ** @return sf::Sprite 
             */
            sf::Sprite getSprite();

            /**
             ** @brief Set the Rotation object
             ** 
             ** @param angle 
             */
            void setRotation(float angle);

            /**
             ** @brief Set the Hitbox object
             ** 
             ** @param rect 
             */
            void setHitbox(sf::IntRect rect);

            /**
             ** @brief Get the Hitbox object
             ** 
             */
            struct SpritePosition {
                int x;
                int y;
                quint32 sprite_x;
                quint32 sprite_y;
            };
        
        
            /**
             ** @brief set the sprite size
             ** 
             */
            struct SpriteSize {
                int width;
                int height;
            };

            /**
             ** @brief Get the Sprite Sheet Index object
             ** 
             ** @return quint32 
             */
            quint32 getSpritesheetIndex() const;

            /**
             ** @brief Get the Sheet Position object
             ** 
             ** @return std::vector<int> 
             */
            std::vector<quint32> getSheetPosition() const;

            /**
             ** @brief Get the Sheet Size object
             ** 
             ** @return std::vector<quint32> 
             */
            std::vector<quint32> getSheetSize() const;


            /**
             ** @brief Get the Scale object
             ** 
             ** @return quint32 
             */
            quint32 getScale() const;

            /**
             ** @brief Get the Position object
             ** 
             ** @return quint32 
             */
            std::vector<quint32> getPosition() const;

            SpriteSize size;
            int nb_sprites;
            int counter_sprites;
            quint32 initial_sprite_x;
            SpritePosition position;

        protected:
        private:
            quint32 _spritesheetIndex;
            sf::Texture texture;
            sf::Sprite sprite;
            bool isPrintable;
            float angle;
            sf::IntRect rect;
            quint32 _scale;
    };

}

#endif /* !GRAPHICCOMPONENT_HPP_ */
