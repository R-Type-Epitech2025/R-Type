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
            /*
            ** @brief Called when a datagram is received on the UDP socket
            ** 
            ** @param msg the message received already deserialized
            */
            void onMessageReceived(Message &msg, quint32 id);

            /**
             ** @brief Called when the GameSystem has received a message from the client
             ** 
             ** @param entities 
             */
            void onSendUpdatedEntities(std::vector<Entity *> &entities);

            /*
            ** @brief Called when a new player connects to the server
            ** 
            ** @param id the id of the new player
            */
            void onNewPlayerConnected(quint32 id);

        signals:
            /**
            ** @brief Emitted when a player moves - Received by the GameSystem
            *
            */
            void playerMoveEvent(quint32 id, DIRECTION dir);

            /*
            **  @brief Emitted when a player shoots - Received by the GameSystem
            **  
            */
            void playerShootEvent(quint32 id);

            /*
            **  @brief Emitted when a player quits - Received by the GameSystem
            **  
            */
            void playerQuitEvent(quint32 id);

            /*
            ** @brief Emitted when a player connects - Received by the GameSystem
            ** 
            ** @param id the id of the new player
            */
            void playerConnectEvent(quint32 id);

        protected:
        private:
            UDPSocket *_udpSocket;
    };
}

#endif /* !NETWORKSYSTEM_HPP_ */
