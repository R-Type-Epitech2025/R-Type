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

    struct waves {
        uint64_t spawnTime;
        bool isLoaded;
        std::vector<Entity *> wave;
    };

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

            /**
             ** @brief Update the game
             ** 
             ** @param sceneManager the scene manager
             ** @param elapsedTime the elapsed time
             */
            void update(SceneManager *sceneManager, uint64_t elapsedTime);
            Entity* bulletSpawner(Entity *entity);
            void ennemyShoot(Scene *scene, uint64_t elapsedTime);
            int idGenerator();
            int id = 42;
            std::vector<Entity *> CreateWave1();
            std::vector<Entity *> CreateWave2();
            // std::vector<Entity *> CreateWave3();
            std::vector <waves> waveContainer;
            Entity* bullets;
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

        signals:
            /**
             ** @brief Emitted when there is an update to send to the client
             ** 
             */
            void sendUpdatedEntities(std::vector<Entity *> entities);
        protected:
        private:
    };
}

#endif /* !GAMESYSTEM_HPP_ */
