/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** NetworkSystem
*/

#ifndef CLIENT_HPP_
#define CLIENT_HPP_

#include "NetworkSystem.hpp"
#include "UDPSocket.hpp"

namespace rtype{
    namespace system {

        class NetworkSystem : public QObject, public ISystem {

            Q_OBJECT

            public:
                NetworkSystem(QObject *parent, QString addr, quint32 port);
                virtual ~NetworkSystem() {};

                void linkToMovementSystem(MovementSystem *movementSystem);
                void linkToGraphicsSystem(GraphicSystem *graphicSystem);

            public slots:
                void onSendMovePlayer(DIRECTION dir);
                void onMessageReceived(Message &msg);

            signals:
                void onUpdateSprites(std::list<Sprite *> sprites);


            protected:
            private:
                UDPSocket *_udpSocket;
        };
    }
}

#endif /* !CLIENT_HPP_ */
