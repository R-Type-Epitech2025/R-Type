/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** IEntity
*/

#ifndef IENTITY_HPP
#define IENTITY_HPP

#include <map>
#include <memory>
#include "components/IComponent.hpp"

namespace rtype
{
    class IEntity
    {
    public:
        enum class Tags {
            MOVABLE,
            AUDIBLE,
            DESTROYABLE,
            COLIDABLE
        };

        virtual ~IEntity() = default;

        virtual IEntity &addComponent(std::shared_ptr<IComponent> component) = 0;
        // virtual IEntity &addComponents(std::vector<std::shared_ptr<IComponent>> components) = 0;
        virtual std::map<IComponent::Type, std::shared_ptr<IComponent>> &getComponents() = 0;
        // virtual const std::vector<Tags> &getTags() const = 0;

        virtual bool hasTag(Tags tag) const = 0;
        virtual bool hasComponent(IComponent::Type type) const = 0;
        // virtual std::vector<std::shared_ptr<IComponent>> getFilteredComponents(std::vector<IComponent::Type> components) = 0;
        // virtual std::shared_ptr<IComponent> &operator[](IComponent::Type type) = 0;
    };
}

#endif /* !IENTITY_HPP */
