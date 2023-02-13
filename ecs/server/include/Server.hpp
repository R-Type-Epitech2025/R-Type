/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Server
*/

#ifndef SERVER_HPP_
#define SERVER_HPP_

#include "NetworkSystem.hpp"
#include "UDPSocket.hpp"


enum ACTION {
   OK,
   KO,
   CONNECT,
   CREATE,
   LIST,
   JOIN,
   JOINED,
   READY,
   START
};

class Server : public QObject, public NetworkSystem {

    Q_OBJECT

    public:
        Server(QObject *parent, quint16 port);
        ~Server();

    public slots:
        void onNewTcpConnection();
        void onTcpReadyRead();

        void onUdpMessage(Message msg);
        void onSendSprites();

    signals:
        void moveEvent(QString name, DIRECTION dir);
        void shootEvent(QString name);
        void quitEvent(QString name);

    protected:
    private:
        QTcpServer *_tcpServer;
        UDPSocket _udpSocket;

        QMap<QTcpSocket *, QString> _clients;
        QString _lobbyName;
};


#endif /* !SERVER_HPP_ */
