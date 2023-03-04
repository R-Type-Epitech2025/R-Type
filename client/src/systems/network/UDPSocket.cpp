/*
** EPITECH PROJECT, 2023
** server
** File description:
** UDPSocket
*/

#include "UDPSocket.hpp"

namespace rtype {
    UDPSocket::UDPSocket(QObject *parent, QString serverIp, int port): QObject(parent)
    {
        _socket = new QUdpSocket(this);
        if (!_socket->bind(QHostAddress::LocalHost, 8080)) {
            throw std::invalid_argument("UDP Socket bind failed");
        }
        if (!connect(_socket, SIGNAL(readyRead()), this, SLOT(onMessageReceived()), Qt::QueuedConnection)) {
            throw std::invalid_argument("Connect failed");
        }
        _serverAddress = QHostAddress(serverIp);
        _serverPort = port;
        askConnection();
    }

    // UDPSocket::~UDPSocket()
    // {
    // }

    void UDPSocket::onMessageReceived()
    {
        while (_socket->hasPendingDatagrams()) {
            QNetworkDatagram data = _socket->receiveDatagram();
            QDataStream ds(data.data());
            Message msg;

            ds >> msg;
            emit messageReceived(msg);
        }

    }

    void UDPSocket::sendDatagram(QByteArray &data)
    {
        _socket->writeDatagram(data, _serverAddress, _serverPort);
    }

    void UDPSocket::askConnection()
    {
        QByteArray datagram;
        QDataStream out(&datagram, QIODevice::WriteOnly);

        out << static_cast<quint32>(EVENT::CONNECT);

        _socket->writeDatagram(datagram, _serverAddress, _serverPort);
    }
}