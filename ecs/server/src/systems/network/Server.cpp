/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Server
*/

#include "Server.hpp"

Server::Server(QObject *parent, quint16 port): QObject(parent), _udpSocket(this, QHostAddress::AnyIPv6, port), _lobbyName("")
{
    _tcpServer = new QTcpServer(this);

    QHostAddress address = QHostAddress::AnyIPv6;

    connect(&_udpSocket, &UDPSocket::messageReceived, this, &Server::onUdpMessage);
    connect(_tcpServer, SIGNAL(newConnection()), this, SLOT(onNewTcpConnection()));

    if (!_tcpServer->listen(address, port)) {
        std::cerr << "Couldn't start TCP server" << std::endl;
        return;
    }
    std::cout << "Server started on IP: " << QHostAddress(address).toString().toStdString() << " and PORT: " << port << std::endl;
}

Server::~Server()
{
}

void Server::onNewTcpConnection()
{
    QTcpSocket *socket = _tcpServer->nextPendingConnection();
    std::cout << "New connection from: " << socket->peerAddress().toString().toStdString() << std::endl;

    connect(socket, SIGNAL(disconnected()), socket, SLOT(deleteLater()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(onTcpReadyRead()));
}

void Server::onTcpReadyRead()
{
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());

    QDataStream in(socket);

    while (socket->bytesAvailable() > 0) {
        int action = 0;
        in >> action;

        switch (action) {
            case ACTION::CONNECT:
            {
                std::cout << "CONNECT" << std::endl;
                _clients[socket] = "";
                quint8 nameSize = 0;
                in >> nameSize;
                for (int i = 0; i < nameSize; i++) {
                    quint8 c;
                    in >> c;
                    _clients[socket].push_back(c);
                }
                // Send OK
                QByteArray block;
                QDataStream out(&block, QIODevice::WriteOnly);
                out << ACTION::OK;
                socket->write(block);
                break;
            }
            case ACTION::CREATE:
            {
                if (_clients[socket] == "" || !_clients.contains(socket) || _lobbyName != "") {
                    // Send KO
                    QByteArray block;
                    QDataStream out(&block, QIODevice::WriteOnly);
                    out << ACTION::KO;
                    socket->write(block);
                    break;
                }
                std::cout << "CREATE" << std::endl;
                _lobbyName = "";
                quint8 nameSize = 0;
                in >> nameSize;
                for (int i = 0; i < nameSize; i++) {
                    quint8 c;
                    in >> c;
                    _lobbyName.push_back(c);
                }
                // Send OK
                QByteArray block;
                QDataStream out(&block, QIODevice::WriteOnly);
                out << ACTION::OK;
                socket->write(block);
                break;
            }
            case ACTION::LIST:
                std::cout << "LIST" << std::endl;
                
                break;
            case ACTION::JOIN:
                std::cout << "JOIN" << std::endl;
                break;
            case ACTION::JOINED:
                std::cout << "JOINED" << std::endl;
                break;
            case ACTION::READY:
                std::cout << "READY" << std::endl;
                break;
            case ACTION::START:
                std::cout << "START" << std::endl;
                break;
            default:
                std::cout << "Unknown action" << std::endl;
                break;
        }
    }
}

void Server::onUdpMessage(Message msg)
{
    UDPSocket *socket = qobject_cast<UDPSocket *>(sender());

    if (msg.getEvent() == EVENT::MOVE) {
        emit moveEvent("user", DIRECTION::LEFT);
    } else if (msg.getEvent() == EVENT::SHOOT) {
        emit shootEvent("user");
    } else if (msg.getEvent() == EVENT::QUIT) {
        emit quitEvent("user");
    } else {
        std::cout << "Unknown event" << std::endl;
    }
}