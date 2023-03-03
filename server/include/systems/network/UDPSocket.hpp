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

    struct Client
    {
        QHostAddress address;
        quint16 port;
        quint8 id;
    };
    
    class UDPSocket : public QObject 
    {
        Q_OBJECT

    public:
        /*
        ** @brief Construct a new UDPSocket object
        ** 
        ** @param parent Set the parent of the object - Normally the NetworkSystem
        */
        UDPSocket(QObject *parent);

        /*
        ** @brief Destroy the UDPSocket object
        ** 
        */
        virtual ~UDPSocket() {};

        /*
        ** @brief Send a datagram to all connected clients
        ** 
        ** @param data the datagram already serialized
        */
        void sendDatagram(QByteArray &data);

        std::list<Client> _clients;
    public slots:
        /*
        ** @brief Called when a datagram is received
        ** 
        */
        void onMessageReceived();

    signals:
        /*
        ** @brief Emitted to the NetworkSystem when a datagram is received
        ** 
        ** @param msg the message received, and tranformed into a Message object
        */
        void messageReceived(Message &msg);

    private:

        /*
        ** @brief Check if the client sending the datagram is already connected
        ** 
        ** @param addr the address of the client
        ** @param port the port of the client
        ** @return true if the client is already connected
        ** @return false if the client is not connected
        */
        bool alreadyConnected(const QHostAddress &addr, quint16 port);

        QUdpSocket *_socket;
    };
}


#endif /* !UDPSOCKET_HPP_ */
