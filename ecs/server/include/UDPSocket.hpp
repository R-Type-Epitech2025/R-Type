/*
** EPITECH PROJECT, 2023
** server
** File description:
** UDPSocket
*/

#ifndef UDPSOCKET_HPP_
#define UDPSOCKET_HPP_

#include <iostream>
#include <QObject>
#include <QtNetwork>
#include "Message.hpp"

class UDPSocket : public QObject 
{
    Q_OBJECT

public:
    UDPSocket(QObject *parent = nullptr, QHostAddress addr = QHostAddress::AnyIPv4,
        int port = 0, QAbstractSocket::BindMode mode = QAbstractSocket::DefaultForPlatform);
    ~UDPSocket();

public slots:
    void onMessageReceived();

signals:
    void messageReceived(Message &msg);

private:
    QUdpSocket *_socket;
};


#endif /* !UDPSOCKET_HPP_ */
