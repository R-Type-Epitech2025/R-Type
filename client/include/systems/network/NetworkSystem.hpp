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
             * @brief Construct a new Network System object
             * 
             * @param parent 
             * @param addr 
             * @param port 
             */
            NetworkSystem(QObject *parent, QString addr, quint32 port);

            /**
             * @brief Destroy the Network System object
             * 
             */
            ~NetworkSystem() {};

            /**
             * @brief Get the Type object
             * 
             * @return SystemType 
             */
            SystemType getType();

        public slots:
            /**
             * @brief slot activated when a player movement is send by the movement system
             * 
             * @param dir 
             */
            void onSendMovePlayer(rtype::DIRECTION dir);

            /**
             * @brief slot activated when a message is received in the UDP socket
             * 
             */
            void onMessageReceived(Message &msg);

        signals:
            /**
             * @brief signal emitted when the sprites need to be updated
             * 
             * @param entities 
             */
            void updateSprites(std::vector<Entity *> entities);

        protected:
        private:
            UDPSocket *_udpSocket;
    };
}

#endif /* !CLIENT_HPP_ */
