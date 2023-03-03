/*
** EPITECH PROJECT, 2023
** server
** File description:
** Message
*/

#ifndef MESSAGE_HPP_
#define MESSAGE_HPP_

#include <QDataStream>
#include <QNetworkDatagram>
#include <QtNetwork>
#include <SFML/Graphics.hpp>
#include "ISystem.hpp"

namespace rtype {
    enum class EVENT {
        MOVE,
        SHOOT,
        QUIT,
        CONNECT
    };

    class Message {
    public:
        Message();
        ~Message();

        friend QDataStream &operator>>(QDataStream &in, Message &msg);
        
        std::vector<Entity *> getEntities() const;

    private:
        friend QDataStream &readMessage(QDataStream &in, Message &msg);
        
        std::vector<Entity *> _entities;
    protected:

    };
}

#endif /* !MESSAGE_HPP_ */
