/*
** EPITECH PROJECT, 2023
** server
** File description:
** UDPSocket
*/

#include "UDPSocket.hpp"

UDPSocket::UDPSocket(QObject *parent, QHostAddress addr, int port, QAbstractSocket::BindMode mode): QObject(parent)
{
    _socket = new QUdpSocket(this);
    if (!_socket->bind(addr, port, mode)) {
        throw std::invalid_argument("UDP Socket bind failed");
    }
    if (!connect(_socket, SIGNAL(QUdpSocket::readyRead), this, &UDPSocket::onMessageReceived, Qt::QueuedConnection)) {
        throw std::invalid_argument("UDP Socket connect failed");
    }
    std::cout << "UDP Socket binded on " << addr.toString().toStdString() << ":" << port << std::endl;
}

UDPSocket::~UDPSocket()
{
}

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