/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** IScene
*/

#ifndef ISCENE_HPP
#define ISCENE_HPP

#include <map>
#include <memory>
#include <vector>
#include "IEntity.hpp"

namespace rtype
{
    class IScene
    {
    public:

        /**
         * @brief destroy the IScene object
         * 
         */
        virtual ~IScene() = default;

        /**
         * @brief update the scene
         * 
         */
        virtual void update() = 0;

        /**
         * @brief draw the scene
         * 
         */
        virtual void draw() = 0;
    };
}

#endif /* !ISCENE_HPP */
