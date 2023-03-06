/*
** EPITECH PROJECT, 2023
** client
** File description:
** EntityCreator
*/

#ifndef ENTITYCREATOR_HPP_
#define ENTITYCREATOR_HPP_
#include <SFML/Graphics.hpp>
#include <QtNetwork>
#include <memory>
#include <iostream>
#include <vector>

namespace rtype {
    typedef struct EntityCreator
    {
        std::vector<int> positionInScreen;
        std::vector<int> posSheet;
        std::vector<int> sizeSheet;
        float scale;
        std::string spriteName;
        quint32 id;
    } EntityCreator_t;
}

#endif /* !ENTITYCREATOR_HPP_ */
