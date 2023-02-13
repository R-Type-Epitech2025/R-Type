/*
** EPITECH PROJECT, 2023
** client
** File description:
** Text
*/

#ifndef TEXT_HPP_
#define TEXT_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Position.hpp"

class Text {
    public:

        /**
         * @brief Construct a new Text object
         * 
         * @param fontpath 
         * @param str 
         * @param Size 
         * @param color 
         */
        Text(std::string fontpath, std::string str, int Size, sf::Color color);
        
        /**
         * @brief Destroy the Text object
         * 
         */
        ~Text();

        /**
         * @brief Print the Text
         * 
         */
        void printText(Position position);

    protected:
    private:
        sf::Font _font;
        sf::Text _text;
};

#endif /* !TEXT_HPP_ */
