/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** server
*/

#ifndef SERVER_HPP_
#define SERVER_HPP_

#include <iostream>
#include <QtNetwork>
#include <QtCore>

class Server : public QObject
{
    Q_OBJECT

    public:
        Server(QObject *parent = nullptr, QHostAddress ip = QHostAddress::LocalHost, quint16 port = 8080);
        ~Server();

    public slots:
        void readPendingDatagrams();

    private:
        QUdpSocket *_socket;
};


#endif /* !SERVER_HPP_ */
