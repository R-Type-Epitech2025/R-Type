/*
**  EPITECH PROJECT, 2023
**  client
**  File description:
**  GameSystem
*/

#ifndef GAMESYSTEM_HPP_
#define GAMESYSTEM_HPP_

#include "ISystem.hpp"

namespace rtype{
    class GameSystem : public QObject {

        Q_OBJECT

        public:
            /**
             ** @brief Construct a new Game System object
             ** 
             ** @param parent 
             */
            GameSystem(QObject *parent = nullptr);
            /**
             ** @brief Destroy the Game System object
             ** 
             */
            ~GameSystem();

        public slots:
            /**
             ** @brief Called when a new player connects to the server
             ** 
             ** @param id the id of the new player
             */
            void onNewPlayerConnected(quint32 id);

            /**
             ** @brief Called when a player disconnects from the server
             ** 
             ** @param id the id of the player
             */
            void onPlayerDisconnected(quint32 id);

            /**
             ** @brief Called when a player shoots
             ** 
             ** @param id the id of the player
             */
            void onPlayerShoot(quint32 id);

            /**
             ** @brief 
             **
             ** @param imagePath 
             ** @param imageForeground 
             ** @param speed 
             ** @param x 
             ** @param y 
             ** @param width 
             **/
            void GameSystem::parralax(std::string imagePath, std::string imageForeground, float speed, float x, float y, float width);



        protected:
        private:
            GameComponent _game;
    };
}

#endif /* !GAMESYSTEM_HPP_ */
