/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** IComponent.hpp
*/

#ifndef ICOMPONENT_HPP
#define ICOMPONENT_HPP

namespace rtype
{
    class IEntity;
    class IComponent
    {
    public:
        enum class Type {
            SPRITE,
            MODEL,
            HITBOX,
            MUSIC,
            SOUND
        };
        virtual const Type &getType() const = 0;
        virtual bool isInitialized() const = 0;
    };
}

#endif /* ICOMPONENT_HPP */