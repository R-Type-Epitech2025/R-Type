#include "Entity.hpp"

Entity::Entity(const int id)
{
    _id = id;
}

const std::map<Entity::Tags, std::vector<std::vector<IComponent::Type>>> entityTags = {
    {Entity::Tags::TEXT,
        {{IComponent::Type::TEXT, IComponent::Type::POSITION}}},
}