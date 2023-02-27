/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** NetworkSystem
*/

#include "NetworkSystem.hpp"

namespace rtype{
    namespace system {
        NetworkSystem::NetworkSystem(QObject *parent, QString ip, quint32 port): QObject(parent)
        {
            try {
                _udpSocket = new UDPSocket(this, ip, port);
            } catch (std::invalid_argument &e) {
                std::cerr << e.what() << std::endl;
                std::cerr << "Please check if the server is running and you have entered the correct IP Address and port" << std::endl;
                std::cerr << "Exiting..." << std::endl;
            }
            connect(_udpSocket, SIGNAL(messageReceived(Message &)), this, SLOT(onMessageReceived(Message &)));
        }

        // NetworkSystem::~NetworkSystem()
        // {
        // }

        void NetworkSystem::onSendMovePlayer(DIRECTION dir)
        {
            QByteArray datagram;
            QDataStream out(&datagram, QIODevice::WriteOnly);

            out << "MOVE";
            out << dir;

            _udpSocket->sendDatagram(datagram);
        }

        void NetworkSystem::onMessageReceived(Message &msg)
        {
            emit updateSprites(msg.getSprites());
        }

        void NetworkSystem::linkToMovementSystem(MovementSystem* movementSystem)
        {
            connect(movementSystem, SIGNAL(sendMovePlayer(DIRECTION dir)), this, SLOT(onSendMovePlayer(DIRECTION dir)));
        }

        void NetworkSystem::linkToGraphicsSystem(GraphicSystem* graphicSystem)
        {
            // connect(this, SIGNAL(updateSprites(std::list<Sprite *> sprites)), graphicSystem, SLOT(onUpdateSprites(std::list<Sprite *> sprites)));
            connect(this, SIGNAL(updateSprites(std::list<sf::Sprite *> sprites)), &graphicSystem, SLOT(onUpdateSprites(std::list<sf::Sprite *> sprites)));
        }
    }
}