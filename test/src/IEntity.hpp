#pragma once

#include "components/IComponent.hpp"
#include <memory>
#include <vector>
#include <map>

class IEntity
{
    public:
        enum class Tags {
            TEXT
        };

        virtual ~IEntity() noexcept = default;
        virtual IEntity &addComponent(std::shared_ptr<IComponent> component) = 0;
        virtual std::map<IComponent::Type, std::vector<std::shared_ptr<IComponent>>> &getComponents() = 0;
        virtual const std::vector<Tags> &getTags() const = 0;
        virtual bool hasTag(Tags tag) const = 0;
        virtual std::shared_ptr<IComponent> &operator[](IComponent::Type type) = 0;
        virtual int get_id() = 0;
};