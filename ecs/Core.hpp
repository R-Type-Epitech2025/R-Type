/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Core
*/

#ifndef CORE_HPP
#define CORE_HPP

#include <map>

#include "systems/ISystem.hpp"
#include "SceneManager.hpp"

namespace rtype
{
    class Core
    {
    public:

        /**
         * @brief Enum of all the system
         * 
         */
        enum class SystemType {
            GAME,
            EVENT,
            AUDIO,
            TEST
        }; 
        Core();

        /**
         * @brief main loop of the game
         * 
         */
        void mainLoop();

        /**
         * @brief load an entity
         * 
         * @param entity 
         */
        void loadEntity(std::shared_ptr<IEntity> entity);

        /**
         * @brief unload an entity
         * 
         * @param entity 
         */
        void unloadEntity(std::shared_ptr<IEntity> entity);
    private:
        std::map<SystemType, std::shared_ptr<ISystem>> _systems;
        SceneManager _sceneManager;
        bool _end = false;
    };
} // namespace rType

#endif // CORE_HPP