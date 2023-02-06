/*
** EPITECH PROJECT, 2023
** client
** File description:
** Sprite
*/

#include "Sprite.hpp"

namespace rtype {
    namespace system {        
        Sprite::Sprite(QDataStream &stream)
        {
            stream >> _id;
            stream >> _x_spritesheet;
            stream >> _y_spritesheet;
            stream >> _width;
            stream >> _height;
            stream >> _x;
            stream >> _y;
        }

        Sprite::~Sprite()
        {
        }
    }
}
