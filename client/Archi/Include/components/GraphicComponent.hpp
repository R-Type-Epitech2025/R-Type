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
            sf::sprite *createSprite;
            struct position{
                int x;
                int y;
                int sprite_x;
                int sprite_y;
            }; 
            typedef struct position position;
            bool isPrintable;
            struct size{
                int width;
                int height;
            };
            typedef struct size size;
        protected:
        private:
    };
}

#endif /* !GRAPHICCOMPONENT_HPP_ */
