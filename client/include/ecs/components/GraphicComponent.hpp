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

    typedef struct EntityCreator
    {
        std::vector<int> positionInScreen;
        std::vector<int> posSheet;
        std::vector<int> sizeSheet;
        float scale;
        std::string spriteName;
        quint32 id;
    } EntityCreator_t;

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
            GraphicComponent(std::string sprite, std::vector<int> positioninsprite_sheet, std::vector<int> sizespritesheet, float scale, std::vector<int> positioninscreen, bool isPrint);

            /**
             ** @brief Construct a new Graphic Component object
             ** 
             ** @param text 
             ** @param positioninscreen 
             ** @param fontSize 
             ** @param textColor 
             */
            GraphicComponent(std::vector<int> positioninscreen, u_int32_t fontSize, sf::Color& textColor, bool isPrint);

            /**
             * @brief Construct a new Graphic Component object
             * 
             * @param entityCreator 
             * @param texture 
             */
            GraphicComponent(EntityCreator_t *entityCreator,sf::Texture *texture);

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
            void setSpritePosition(int x, int y, bool init = false);

            /**
             ** @brief Set the Size object
             ** 
             ** @param scale 
             */
            void setSize(float scale);

            /**
             ** @brief Get the Is Printable object
             ** 
             ** @return true 
             ** @return false 
             */
            bool getIsPrintable();

            
            /**
             ** @brief Get the Text object
             **
             ** @return sf::Text 
             */
            sf::Text getText();

            /**
             ** @brief Get the Input Text object
             ** 
             ** @return std::string 
             */
            std::string getInputText();

            /**
             ** @brief Set the Input Text object
             ** 
             ** @param input 
             */
            void setInputText(std::string input);

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
             * @brief 
             * 
             * @param fonts 
             * @return int 
             */
            int setfont(std::string fonts);


            /**
             * @brief 
             * 
             * @param *entity 
             */
            void update(EntityCreator_t *entity);

            /**
             ** @brief strcut SpritePosition that helps to place the sprite in the window
             ** 
             */
            struct SpritePosition {
                int x;
                int y;
                int sprite_x;
                int sprite_y;
            };
        
            SpritePosition position;
        
            /**
             ** @brief struct SpriteSize that helps to give size to the sprite
             ** 
             */
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
            sf::Font _font;
            sf::Text _text;
            std::string _inputText;
            bool _print;
            float angle;
            sf::IntRect rect;
    };
}

#endif /* !GRAPHICCOMPONENT_HPP_ */
