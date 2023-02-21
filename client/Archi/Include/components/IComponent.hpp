/*
** EPITECH PROJECT, 2023
** client
** File description:
** IComponent
*/

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

#include <memory>
#include <stdexcept>

class IComponent {
    public:
        enum class ComponentType {
            AUDIO,
            EVENT,
            PLAYER,
            ENNEMY,
            POSITION,
            PROJECTILE,
            SPRITE,
            TEXT,
            VELOCITY,
        };
        virtual ~IComponent() = default;
        virtual const ComponentType &getType() const = 0;
};

#endif /* !ICOMPONENT_HPP_ */
