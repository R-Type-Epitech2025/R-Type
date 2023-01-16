/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** server
*/

#include "server.hpp"

Server::Server(QObject *parent, QHostAddress ip, quint16 port) : QObject(parent)
{
    _socket = new QUdpSocket(this);
    std::cout << "Server listening on: " << ip.toString().toStdString() << ":" << port << std::endl;
    _socket->bind(ip, port);
    connect(_socket, SIGNAL(readyRead()), this, SLOT(readPendingDatagrams()));
}

Server::~Server()
{
    delete _socket;
}

void Server::readPendingDatagrams()
{
    while (_socket->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(_socket->pendingDatagramSize());
        QHostAddress sender;
        quint16 senderPort;

        _socket->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);
        std::cout << "Message from: " << sender.toString().toStdString() << std::endl;
        std::cout << "Message port: " << senderPort << std::endl;
        std::cout << "Message: " << datagram.data() << std::endl;
    }
}

int main(int argc, char *argv[])
{
    std::cout << "Server starting !" << std::endl;

    QCoreApplication app(argc, argv);
    Server server;
    return app.exec();
}
