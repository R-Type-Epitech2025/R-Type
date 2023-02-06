/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Client
*/

#include "Client.hpp"

Client::Client(QObject *parent): QObject(parent)
{
    _udpSocket = new ();
    _tcpSocket = new QTcpSocket();

}

Client::~Client()
{
}

