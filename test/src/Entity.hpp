#pragma once

#include "IEntity.hpp"

class Entity : 
    public IEntity
{
    public:
        Entity(const int UID);
        IEntity &addComponent(std::shared_ptr<IComponent> component);
        const std::vector<Tags> &getTags() const {return (_tags);};
        std::shared_ptr<IComponent> &operator[](IComponent::Type type);
    private:
        std::vector<Tags> _tags;
        std::map<IComponent::Type, std::vector<std::shared_ptr<IComponent>>> _components;
        std::vector<IComponent::Type> _componentsType;
    protected:
        int _id;
};