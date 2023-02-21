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
    namespace system {
        class UDPSocket : public QObject 
        {
            Q_OBJECT

        public:
            UDPSocket(QObject *parent, QString serverIp, int port);
            virtual ~UDPSocket() {};

            void sendDatagram(QByteArray &data);

            void askConnection();

        public slots:
            void onMessageReceived();

        signals:
            void messageReceived(Message &msg);

        private:
            QUdpSocket *_socket;
            QHostAddress _serverAddress;
            quint16 _serverPort;
        };
    }
}


#endif /* !UDPSOCKET_HPP_ */
