#pragma once

class IEntity;

class IComponent
{
    public:
        enum class Type {
            POSITION,
            TEXT
        };
        virtual ~IComponent() = default;
        virtual const Type &getType() const = 0;
};