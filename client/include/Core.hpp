/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Core
*/

#ifndef CORE_HPP
#define CORE_HPP

#include "SystemManager.hpp"
#include <QCoreApplication>
#include <QTimer>
#include <QObject>
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
        //, SceneManager *scenemanager
        int run(int argc, char **argv);
        ~Core();
        // void loadEntity(std::shared_ptr<IEntity> entity);
        // void unloadEntity(std::shared_ptr<IEntity> entity);
    private:
        SceneManager *_sceneManager;
        SystemManager *_systemManager;
        bool _end = false;
    };
} // namespace rType

#endif // CORE_HPP