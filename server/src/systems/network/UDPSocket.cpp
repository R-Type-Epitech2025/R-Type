/*
** EPITECH PROJECT, 2023
** server
** File description:
** UDPSocket
*/

#include "UDPSocket.hpp"

namespace rtype {
    UDPSocket::UDPSocket(QObject *parent): QObject(parent)
    {
        _socket = new QUdpSocket(this);
        if (!_socket->bind(QHostAddress::LocalHost, 4242)) {
            throw std::invalid_argument("UDP Socket bind failed");
        }
        if (!connect(_socket, SIGNAL(readyRead()), this, SLOT(onMessageReceived()), Qt::QueuedConnection)) {
            throw std::invalid_argument("UDP Socket connect failed");
        }
        std::cout << "UDP Socket binded on IP: " << _socket->localAddress().toString().toStdString() << " and port: " << _socket->localPort() << std::endl;
    }

    // UDPSocket::~UDPSocket()
    // {
    // }

    void UDPSocket::onMessageReceived()
    {
        std::cout << "Message received" << std::endl;
        while (_socket->hasPendingDatagrams()) {
            std::cout << "\tDatagram received" << std::endl;
            QNetworkDatagram data = _socket->receiveDatagram();
            if (alreadyConnected(data.senderAddress(), data.senderPort()))
                continue;
            else {
                std::cout << "\t\tNew client connected" << std::endl;
                if (_clients.size() >= 4)
                    return;
                else {
                    QDataStream ds(data.data());
                    Message msg;

                    ds >> msg;
                    if (msg->getEvent() != PLAYER_EVENT::CONNECT) {
                        std::cout << "\t\t\tWrong message received" << std::endl;
                        return;
                    }
                    std::cout << "\t\t\tAdding client to known clients" << std::endl;
                    Client client;
                    client.address = data.senderAddress();
                    client.port = data.senderPort();
                    client.id = createId(client.address, client.port);
                    _clients.push_back(client);
                    emit newPlayerConnected(client.id);
                }
                return;
            }
            QDataStream ds(data.data());
            Message msg;

            ds >> msg;
            for (auto &client : _clients) {
                if (client.address == data.senderAddress() && client.port == data.senderPort()) {
                    emit messageReceived(msg, client.id);
                    break;
                }
            }
        }
    }

    void UDPSocket::sendDatagram(QByteArray &data)
    {
        for (auto &client : _clients)
            _socket->writeDatagram(data, client.address, client.port);
    }

    bool UDPSocket::alreadyConnected(const QHostAddress &addr, quint16 port)
    {
        for (auto &client : _clients) {
            if (client.address == addr && client.port == port)
                return true;
        }
        return false;
    }

    quint16 UDPSocket::createId(const QHostAddress &addr, quint16 port)
    {
        quint32 combined = (addr.toIPv4Address() << 16) | port;
    
        // Use a hash function to map the combined value to a 16-bit ID
        std::hash<quint32> hash_func;
        quint16 id = hash_func(combined);
        
        return id;
    }
}
