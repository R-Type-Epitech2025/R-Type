/*
** EPITECH PROJECT, 2023
** server
** File description:
** UDPSocket
*/

#ifndef UDPSOCKET_HPP_
#define UDPSOCKET_HPP_

#include "Message.hpp"

namespace rtype {
    class UDPSocket : public QObject 
    {
        Q_OBJECT

    public:
        /**
         * @brief Construct a new UDPSocket object
         * 
         * @param parent 
         * @param serverIp 
         * @param port 
         */
        UDPSocket(QObject *parent, QString serverIp, int port);

        /**
         * @brief Destroy the UDPSocket object
         * 
         */
        virtual ~UDPSocket() {};

        /**
         * @brief Send a datagram to the server
         * 
         * @param data 
         */
        void sendDatagram(QByteArray &data);

        /**
         * @brief asks connection to the server
         * 
         */
        void askConnection();

    public slots:
        /**
         * @brief slot activated when a message is received in the UDP socket
         * 
         */
        void onMessageReceived();

    signals:
        /**
         * @brief signal emitted when a message is received, it is then processed by the network system
         * 
         * @param msg 
         */
        void messageReceived(Message &msg);

    private:
        QUdpSocket *_socket;
        QHostAddress _serverAddress;
        quint16 _serverPort;
    };
}


#endif /* !UDPSOCKET_HPP_ */
