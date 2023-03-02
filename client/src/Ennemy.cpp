/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** ennemy
*/

#include "ecs/components/GraphicComponent.hpp"
#include "ecs/Entity.hpp"

namespace rtype
{
    Entity *spawnEnnemy()
    {
        Entity *entity = new Entity(rtype::EntityType::MOB, {0, 0}, {0, 0}, {666, 375}, {1920, 1080}, "./assets/logo-transp.png", "ennemy1");
        return entity;
    }
}