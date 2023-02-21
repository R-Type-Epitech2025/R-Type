/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Server
*/

#ifndef SERVER_HPP_
#define SERVER_HPP_

#include "NetworkSystem.hpp"
#include "UDPSocket.hpp"


namespace rtype{
    namespace server {

        class Server : public QObject {

            Q_OBJECT

            public:
                /*
                ** @brief Construct a new Server object
                ** 
                ** @param parent the parent of the object - Normally the QCoreApplication
                */
                Server(QObject *parent);

                /*
                ** @brief Destroy the Server object
                ** 
                */
                virtual ~Server() {};

            public slots:
                /*
                ** @brief Called when a datagram is received on the UDP socket
                ** 
                ** @param msg the message received already deserialized
                */
                void onMessageReceived(Message &msg);

                /*
                ** @brief Called when the GameSystem has updated entities to send to the clients
                ** 
                ** @param entities a vector of shared_ptr to IEntity
                */
                void onSendUpdatedEntities(std::vector<std::shared_ptr<Sprite>> &entities);

            signals:
                /*
                ** @brief Emitted when a player moves - Received by the GameSystem
                ** 
                */
                // void playerMoveEvent(quint16 id, DIRECTION dir);

                /*
                ** @brief Emitted when a player shoots - Received by the GameSystem
                ** 
                */
                // void playerShootEvent(quint16 id);

                /*
                ** @brief Emitted when a player quits - Received by the GameSystem
                ** 
                */
                // void playerQuitEvent(quint16 id);

            protected:
            private:
                UDPSocket *_udpSocket;
        };
    }
}

#endif /* !SERVER_HPP_ */
