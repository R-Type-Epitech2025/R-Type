/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** ISystem
*/

#ifndef ISYSTEM_HPP
#define ISYSTEM_HPP
#include "ecs/SceneManager.hpp"
#include <QObject>

namespace rtype {
    
    enum SystemType {
        MOVEMENT,
        GRAPHIC,
        AUDIO,
        EVENT,
        GAME,
        NETWORK
    };

    class ISystem 
    {
    public:
        virtual SystemType getType() const = 0;            
        virtual void init(SceneManager &sceneManager) = 0;
        virtual void update(SceneManager &manager, uint64_t time) = 0;
        virtual void destroy() = 0;
        virtual void loadEntity(std::shared_ptr<Entity> entity, Scene &scene) = 0;
        virtual void unloadEntity(std::shared_ptr<Entity> entity, Scene &scene) = 0;
    protected:
    private:
    };
} // namespace rType

#endif /* !ISYSTEM_HPP */
