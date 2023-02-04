#include <iostream>

class SceneManager;

class ISystem {
    public:
        virtual ~ISystem() = default;
        virtual void init(SceneManager &sm) = 0;
        virtual void update(SceneManager &sm, uint64_t deltaTime) = 0;
        virtual void destroy() = 0;
};