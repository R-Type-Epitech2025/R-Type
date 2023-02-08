/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Client
*/

#include "Client.hpp"

namespace rtype{
    namespace system {
        Client::Client(QObject *parent): QObject(parent)
        {
            _udpSocket = new ();
            _tcpSocket = new QTcpSocket();

        }

        Client::~Client()
        {
        }
    }
}

