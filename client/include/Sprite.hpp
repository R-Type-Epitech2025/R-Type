/*
** EPITECH PROJECT, 2023
** client
** File description:
** Sprite
*/

#ifndef SPRITE_HPP_
#define SPRITE_HPP_

#include "ISystem.hpp"

class Sprite {
    public:
        Sprite(QDataStream &stream);
        ~Sprite();

    protected:
    private:
        qint32 _id;
        qint32 _x_spritesheet;
        qint32 _y_spritesheet;
        qint32 _width;
        qint32 _height;
        qint32 _x;
        qint32 _y;

};

#endif /* !SPRITE_HPP_ */
