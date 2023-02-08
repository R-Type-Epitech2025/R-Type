/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Client
*/

#ifndef CLIENT_HPP_
#define CLIENT_HPP_

#include "NetworkSystem.hpp"

namespace rtype{
    namespace system {
        class Client : public QObject, public NetworkSystem {

            Q_OBJECT

            public:
                Client(QObject *parent = nullptr);
                ~Client();

            protected:
            private:
                QHostAddress _serverIp;
                quint16 _serverPort;
                QUdpSocket *_udpSocket;

                QTcpSocket *_tcpSocket;
        };
    }
}

#endif /* !CLIENT_HPP_ */
