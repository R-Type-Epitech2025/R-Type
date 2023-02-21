/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Server
*/

#include "Server.hpp"

namespace rtype{
    namespace server {
        Server::Server(QObject *parent): QObject(parent)
        {
            try {
                _udpSocket = new UDPSocket(this);
            } catch (std::invalid_argument &e) {
                std::cerr << e.what() << std::endl;
                std::cerr << "Exiting..." << std::endl;
                exit(84);
            }
            connect(_udpSocket, SIGNAL(messageReceived(Message &)), this, SLOT(onMessageReceived(Message &)));
            // connect(this, SIGNAL(playerMoveEvent), nullptr, SLOT(nullptr));
            // connect(this, SIGNAL(playerShootEvent), nullptr, SLOT(nullptr));
            // connect(this, SIGNAL(playerQuitEvent), nullptr, SLOT(nullptr));
        }

        // Server::~Server()
        // {
        // }

        void Server::onSendUpdatedEntities(std::vector<std::shared_ptr<Sprite>> &entities)
        {
            QByteArray data;
            QDataStream ds(&data, QIODevice::WriteOnly);

            quint32 nb = 0;

            for (auto &entity : entities) {
                // ds << entity->getId();
                // ds << entity->getPosX();
                // ds << entity->getPosY();
                // ds << entity->getDirection();
                // ds << entity->getSpeed();
                // ds << entity->getHealth();
                // ds << entity->getDamage();
                // ds << entity->getScore();
                // ds << entity->getEntityType();
                // ds << entity->getEntityState();
                ds << nb;
                nb++;
            }
            _udpSocket->sendDatagram(data);
        }


        void Server::onMessageReceived(Message &msg)
        {
            if (msg.getEvent() == EVENT::MOVE)
                std::cout << "MOVE" << std::endl;
                // emit playerMoveEvent(msg.getId(), msg.getDirection());
            else if (msg.getEvent() == EVENT::SHOOT)
                std::cout << "SHOOT" << std::endl;
                // emit playerShootEvent(msg.getId());
            else if (msg.getEvent() == EVENT::QUIT)
                std::cout << "QUIT" << std::endl;
                // emit playerQuitEvent(msg.getId());
            else if (msg.getEvent() == EVENT::CONNECT)
                std::cout << "CONNECT" << std::endl;
                // emit playerConnectEvent(msg.getId());
        }
    }
}

