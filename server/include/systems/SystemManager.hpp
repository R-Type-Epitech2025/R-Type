/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** SystemManager
*/

#ifndef SYSTEMMANAGER_HPP_
#define SYSTEMMANAGER_HPP_

#include "ISystem.hpp"
#include "GraphicSystem.hpp"
#include "MovementSystem.hpp"
#include "NetworkSystem.hpp"
#include "GameSystem.hpp"
#include "EventSystem.hpp"

namespace rtype {

    class SystemManager : public QObject {

        Q_OBJECT
    
        public:
            /**
             ** @brief Construct a new System Manager object
             ** 
             ** @param parent 
             */
            SystemManager(QObject *parent = nullptr);

            /**
             ** @brief Destroy the System Manager object
             ** 
             */
            ~SystemManager();

            /**
             ** @brief create the game system
             **  
             */
            void createGameSystem();

            /**
             ** @brief create the movement system
             **  
             */
            void createMovementSystem();

            /**
             ** @brief create the network system
             **  
             */
            void createNetworkSystem();

            // /**
            //  ** @brief create the event system
            //  **  
            //  */
            // void createEventSystem();

            /**
             ** @brief update the game
             ** 
             ** @param sceneManager the scene manager
             ** @param elapsedTime the elapsed time
             */
            void updateGame(SceneManager *sceneManager, uint64_t elapsedTime);

            // /**
            //  ** @brief update events
            //  ** 
            //  ** @param SceneManager
            //  ** @param sf::Event
            //  **  
            //  */
            // void updateEvents(SceneManager *currentScene, sf::Event &event);

            // /**
            //  ** @brief update graphic
            //  ** 
            //  ** @param SceneManager
            //  ** @param time
            //  **  
            //  */
            // void updateGraphic(SceneManager *Manager, uint64_t time);

            // /**
            //  ** @brief update movement
            //  ** 
            //  ** @param SceneManager
            //  ** @param sf::Event
            //  **  
            //  */
            // void updateMovement(SceneManager *Manager, sf::Event &event);

            // /**
            //  ** @brief quit the game
            //  ** 
            //  */
            // void gameQuit();

            GameSystem *gameSystem;
            MovementSystem *movementSystem;
            NetworkSystem *networkSystem;
            EventSystem *eventSystem;
        protected:
        private:
    };
}

#endif /* !SYSTEMMANAGER_HPP_ */
