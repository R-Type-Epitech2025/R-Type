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
#include "GraphicComponent.hpp"
#include "EventComponent.hpp"
#include "MovementComponent.hpp"
#include "GameComponent.hpp"


namespace rtype{
    enum class ComponentType {
            GameComponent = 0,
            GraphicComponent = 1,
            EventComponent = 2,
            MovemementComponent = 3,
            SoundComponent = 4
    };
};


#endif /* !ICOMPONENT_HPP_ */
