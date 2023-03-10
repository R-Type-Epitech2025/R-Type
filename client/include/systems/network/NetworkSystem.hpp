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
             ** @param addr 
             ** @param port 
             */
            NetworkSystem(QObject *parent, QString addr, quint32 port);

            /**
             ** @brief Destroy the Network System object
             ** 
             */
            ~NetworkSystem() {};

            /**
             ** @brief Get the Type object
             ** 
             ** @return SystemType 
             */
            SystemType getType();

        public slots:
            /**
             ** @brief slot activated when a player movement is send by the movement system
             ** 
             ** @param dir 
             */
            void onSendMovePlayer(DIRECTION dir);

            /**
             ** @brief slot activated when a message is received in the UDP socket
             ** 
             */
            void onMessageReceived(Message &msg);

            /**
             ** @brief slot activated when a player shoot is send by the movement system
             ** 
             */
            void onSendShootPlayer();

            /**
             ** @brief slot activated when a player quit is send by the movement system
             ** 
             */
            void onQuitPlayer();

        signals:
            /**
             ** @brief signal emitted when the sprites need to be updated
             ** 
             ** @param entities 
             */
            void updateEntities(std::vector<EntityCreator_t*>);

        protected:
        private:
            UDPSocket *_udpSocket;
    };
}

#endif /* !CLIENT_HPP_ */
