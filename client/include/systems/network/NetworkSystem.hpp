/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** NetworkSystem
*/

#ifndef CLIENT_HPP_
#define CLIENT_HPP_

#include "UDPSocket.hpp"
#include "ISystem.hpp"

namespace rtype{
    namespace system {

        class NetworkSystem : public QObject {

            Q_OBJECT

            public:
                NetworkSystem(QObject *parent, QString addr, quint32 port);
                virtual ~NetworkSystem() {};

                void linkToMovementSystem(rtype::system::MovementSystem* movementSystem);
                void linkToGraphicsSystem(rtype::system::GraphicSystem* graphicSystem);

                // virtual void init(SceneManager &sceneManager) = 0;
                // virtual void update(SceneManager &manager, uint64_t time) = 0;
                // virtual void destroy() = 0;

            public slots:
                void onSendMovePlayer(DIRECTION dir);
                void onMessageReceived(Message &msg);

            signals:
                void updateSprites(std::list<sf::Sprite *> sprites);

            protected:
            private:
                UDPSocket *_udpSocket;
        };
    }
}

#endif /* !CLIENT_HPP_ */
