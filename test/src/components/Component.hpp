#include "IComponent.hpp"

class Component : public IComponent
{
    public:
        Component(const Type &type);
        virtual ~Component() = default;
        const Type &getType() const;
    protected:
        Type _type = Type::POSITION;
        bool _isInitialized = false;
};