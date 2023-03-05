/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** NetworkSystem
*/

#include "NetworkSystem.hpp"

namespace rtype{
        NetworkSystem::NetworkSystem(QObject *parent, QString ip, quint32 port): QObject(parent)
        {
            try {
                std::cout << "Creating socket ..." << std::endl;
                _udpSocket = new UDPSocket(this, ip, port);
                std::cout << "Socket created" << std::endl;
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
            quint32 move = static_cast<quint32>(EVENT::MOVE);
            quint32 direction = static_cast<quint32>(dir);
            out << move;
            out << direction;
            std::cout << "Sending move to server" << std::endl;
            _udpSocket->sendDatagram(datagram);
        }

        void NetworkSystem::onSendShootPlayer()
        {
            QByteArray datagram;
            QDataStream out(&datagram, QIODevice::WriteOnly);
            quint32 shoot = static_cast<quint32>(EVENT::SHOOT);

            out << shoot;
            _udpSocket->sendDatagram(datagram);
        }

        void NetworkSystem::onQuitPlayer()
        {
            QByteArray datagram;
            QDataStream out(&datagram, QIODevice::WriteOnly);
            quint32 quit = static_cast<quint32>(EVENT::QUIT);

            out << quit;
            _udpSocket->sendDatagram(datagram);
        }

        void NetworkSystem::onMessageReceived(Message &msg)
        {
            emit updateEntities(msg.getEntities());
        }

        SystemType NetworkSystem::getType()
        {
            return SystemType::NETWORK;
        }
}