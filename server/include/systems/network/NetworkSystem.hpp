/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** NetworkSystem
*/

#ifndef CLIENT_HPP_
#define CLIENT_HPP_

#include "UDPSocket.hpp"


namespace rtype{

    class NetworkSystem : public QObject {

        Q_OBJECT

        public:
            /**
             ** @brief Construct a new Network System object
             ** 
             ** @param parent 
             */
            NetworkSystem(QObject *parent);

            /**
             ** @brief Destroy the Network System object
             ** 
             */
            virtual ~NetworkSystem() {};

        public slots:
            /**
             ** @brief Called when the GameSystem has received a message from the client
             ** 
             ** @param msg 
             */
            void onMessageReceived(Message &msg);

            /**
             ** @brief Called when the GameSystem has received a message from the client
             ** 
             ** @param entities 
             */
            void onSendUpdatedEntities(std::vector<Entity *> &entities);

        signals:
            /**
            ** @brief Emitted when a player moves - Received by the GameSystem
            *
            */
            // void playerMoveEvent(quint16 id, DIRECTION dir);

            /*
            **  @brief Emitted when a player shoots - Received by the GameSystem
            **  
            */
            // void playerShootEvent(quint16 id);

            /*
            **  @brief Emitted when a player quits - Received by the GameSystem
            **  
            */
            // void playerQuitEvent(quint16 id);

        protected:
        private:
            UDPSocket *_udpSocket;
    };
}

<<<<<<< HEAD
#endif /* !CLIENT_HPP_ */
=======
#endif /* !NETWORKSYSTEM_HPP_ */
>>>>>>> ecs_network_v2.0
