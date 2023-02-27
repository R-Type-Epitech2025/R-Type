/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Core
*/

#ifndef CORE_HPP
#define CORE_HPP

#include "SceneManager.hpp"

namespace rtype
{
    class Core
    {
    public:
        enum class SystemType {
            GAME,
            EVENT,
            AUDIO,
            TEST
        }; 
        Core();
        void mainLoop();
        void loadEntity(std::shared_ptr<IEntity> entity);
        void unloadEntity(std::shared_ptr<IEntity> entity);
    private:
        SceneManager _sceneManager;
        bool _end = false;
    };
} // namespace rType

#endif // CORE_HPP