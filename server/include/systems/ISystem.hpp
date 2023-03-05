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
    
    /**
     ** @brief SystemType enum 
     ** 
     */
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
        /**
         ** @brief Get the Type object
         ** 
         ** @return SystemType 
         */
        virtual SystemType getType() const = 0;   

        /**
         ** @brief init the system
         ** 
         ** @param SceneManager 
         */         
        virtual void init(SceneManager &sceneManager) = 0;

        /**
         ** @brief update the system
         ** 
         ** @param SceneManager 
         ** @param deltaTime 
         */
        virtual void update(SceneManager &manager, uint64_t time) = 0;

        /**
         ** @brief destroy the system
         ** 
         ** @param SceneManager 
         */
        virtual void destroy() = 0;

        /**
         ** @brief load the system
         ** 
         */
        virtual void loadEntity(std::shared_ptr<Entity> entity, Scene &scene) = 0;

        /**
         ** @brief unload the system
         ** 
         */
        virtual void unloadEntity(std::shared_ptr<Entity> entity, Scene &scene) = 0;
    protected:
    private:
    };
} // namespace rType

#endif /* !ISYSTEM_HPP */

