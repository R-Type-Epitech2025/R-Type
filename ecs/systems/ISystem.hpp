/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** ISystem
*/

#ifndef ISYSTEM_HPP
#define ISYSTEM_HPP

#include <memory>

namespace rtype 
{    
    class SceneManager;
    class IEntity;

    class ISystem 
    {
    public:
        virtual void init(SceneManager &sceneManager) = 0;
        virtual void update(SceneManager &manager, uint64_t time) = 0;
        virtual void destroy() = 0;
        virtual void loadEntity(std::shared_ptr<IEntity> entity) = 0;
        virtual void unloadEntity(std::shared_ptr<IEntity> entity) = 0;
    protected:
    private:
    };
} // namespace rType

#endif /* !ISYSTEM_HPP */
