/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Core
*/

#ifndef CORE_HPP
#define CORE_HPP

#include "ecs/SceneManager.hpp"
#include <QCoreApplication>
#include <QTimer>
#include <QObject>
namespace rtype
{
    class Core
    {
    public:
    /**
     ** @brief enum class SystemType
     ** 
     */
        enum class SystemType {
            GAME,
            EVENT,
            AUDIO,
            TEST
        }; 

        /**
         ** @brief Construct a new Core object
         ** 
         */
        Core();
        //, SceneManager *scenemanager

        /**
         ** @brief run the core
         ** 
         ** @param argc 
         ** @param argv 
         ** @return int 
         */
        int run(int argc, char ** argv);

        /**
         ** @brief Destroy the Core object
         ** 
         */
        ~Core();
        // void loadEntity(std::shared_ptr<IEntity> entity);
        // void unloadEntity(std::shared_ptr<IEntity> entity);
    private:
        SceneManager *_sceneManager;
        bool _end = false;
    };
} // namespace rType

#endif // CORE_HPP